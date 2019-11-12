#
# (C) Copyright 2003
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# See file CREDITS for list of people who contributed to this
# project.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA
#

#
# Falcon SoC with MIPS 34Kc CPU core
#

################################################################################
# Code to create simple BootROM images (only using download and start tags)
################################################################################


# only active in topdir
ifeq ($(subst $(SRCTREE),,$(CURDIR)),)

ALL-y += $(obj)u-boot.dis

# only for target not using eXecute In Place (XIP)
ifneq ($(CONFIG_SYS_TEXT_BASE),0xB0000000)

# add to all target
ALL-y += $(obj)u-boot.bri

# TAGs with FLAG_SDBG set:
#TAG_DWNLD := 0x5508AAF7
#TAG_START := 0x770888F7
#TAG_REGCFG := 0x2208DDF7
#TAG_IFCFG := 0x660899F7

# TAGs without flags set:
TAG_DWNLD := 0x5500AAFF
TAG_START := 0x770088FF
TAG_REGCFG := 0x2200DDFF
TAG_IFCFG := 0x660099FF

define add_val_as_le_bytes
	perl -e 'printf("%c%c%c%c", ($(1))&0xFF, (($(1))>>8)&0xFF, (($(1))>>16)&0xFF, (($(1))>>24)&0xFF)'
endef

define pad_if_less_avail
	# $(1) blocksize
	# $(2) req. room to be free
	# $(3) file
	perl -e 'my $$f="$(3)"; my $$size = -s $$f; $$rest=$(1)-($$size%$(1));if($$rest<$(2)){open(F,">>$$f");for($$i=0;$$i<$$rest;$$i++){print F chr(0);};close(F)}'
endef

define add_padding
	# $(1) blocksize
	# $(2) file
	perl -e 'my $$f="$(2)"; \
		my $$bs=$(1); \
		my $$b; \
		if ($$bs =~/0x/) \
		{$$b=int(hex($$bs))} \
		else \
		{$$b=int($$bs)}; \
		my $$size = -s $$f; \
		$$rest=$$b-($$size%$$b); \
		open(F,">>$$f"); \
		for($$i=0;$$i<$$rest;$$i++) \
		{print F chr(0);}; \
		close(F)'
endef

# tweak some ebu registers to optimize performance for booting from flash
ifneq ($(CONFIG_FLASH_CFI_DRIVER),)
define add_ebu_setup
	echo "Add TAG_REGCFG for NOR timing"
	# TAG_REGCFG()
	$(call add_val_as_le_bytes,$(TAG_REGCFG)) >> $1
	# length
	$(call add_val_as_le_bytes,16) >> $1
	# Reg BUSRP0
	$(call add_val_as_le_bytes,0xB8000014) >> $1
	$(call add_val_as_le_bytes,0x22252122) >> $1
	# Reg BUSWP0
	$(call add_val_as_le_bytes,0xB800001C) >> $1
	$(call add_val_as_le_bytes,0x22252122) >> $1
endef
endif

ifneq ($(CONFIG_NAND),)
define add_ebu_setup_nand_reg_
	# FIXME: currently unused, need valid register values!
	echo "Add TAG_REGCFG for NAND timing"
	# TAG_REGCFG()
	$(call add_val_as_le_bytes,$(TAG_REGCFG)) >> $1
	# length
	$(call add_val_as_le_bytes,16) >> $1
	# Reg BUSRP0
	$(call add_val_as_le_bytes,0xB8000014) >> $1
	$(call add_val_as_le_bytes,0x00000000) >> $1
	# Reg BUSWP0
	$(call add_val_as_le_bytes,0xB800001C) >> $1
	$(call add_val_as_le_bytes,0x00000000) >> $1
endef

ifneq ($(CONFIG_SYS_NAND_PAGESIZE),)
ifneq ($(CONFIG_SYS_NAND_BYTES_PER_COLADDR),)
define add_ebu_setup_nand_ifcfg
	#echo "Add TAG_IFCFG for large NAND"
	# TAG_IFCFG()
	$(call add_val_as_le_bytes,$(TAG_IFCFG)) >> $1
	# length
	$(call add_val_as_le_bytes,8) >> $1
	$(call add_val_as_le_bytes,$(shell echo $(CONFIG_SYS_NAND_PAGESIZE))) >> $1
	$(call add_val_as_le_bytes,$(shell echo $(CONFIG_SYS_NAND_BYTES_PER_COLADDR))) >> $1
	# pad to start of next page
	#$ ( call add_padding,$(CONFIG_SYS_NAND_PAGESIZE),$1)
	$(call add_padding,0x80,$1)
endef
endif
endif

define add_ebu_setup
	$(call add_ebu_setup_nand_reg,$1)
	# FIXME: we need a valid tag at each 128byte block (small XMODEM blocks)
	# TODO: add some loop code, which depends on CONFIG_SYS_NAND_PAGESIZE
	$(call add_ebu_setup_nand_ifcfg,$1)
	$(call add_ebu_setup_nand_ifcfg,$1)
	$(call add_ebu_setup_nand_ifcfg,$1)
	$(call add_ebu_setup_nand_ifcfg,$1)
	$(call add_ebu_setup_nand_ifcfg,$1)
	$(call add_ebu_setup_nand_ifcfg,$1)
	$(call add_ebu_setup_nand_ifcfg,$1)
	$(call add_ebu_setup_nand_ifcfg,$1)
	$(call add_ebu_setup_nand_ifcfg,$1)
	$(call add_ebu_setup_nand_ifcfg,$1)
	$(call add_ebu_setup_nand_ifcfg,$1)
	$(call add_ebu_setup_nand_ifcfg,$1)
	$(call add_ebu_setup_nand_ifcfg,$1)
	$(call add_ebu_setup_nand_ifcfg,$1)
	$(call add_ebu_setup_nand_ifcfg,$1)
	$(call add_ebu_setup_nand_ifcfg,$1)
endef
endif

ifneq ($(CONFIG_SPI_FLASH),)
define add_ebu_setup
	echo "Add TAG_REGCFG for Serial Flash timing"
	# TAG_REGCFG()
	$(call add_val_as_le_bytes,$(TAG_REGCFG)) >> $1
	# length
	$(call add_val_as_le_bytes,8) >> $1
	# Reg SFTIME
	$(call add_val_as_le_bytes,0xB8000084) >> $1
	$(call add_val_as_le_bytes,0xFF000204) >> $1
endef
endif

$(obj)u-boot.bri:	$(obj)u-boot.bin
	rm -f $@
	$(call add_ebu_setup,$@)
	# make sure, the following elements are not crossing the border of a block
	$(call pad_if_less_avail,128,12,$@)
	# TAG_DWNLD()
	$(call add_val_as_le_bytes,$(TAG_DWNLD)) >> $@
	# length (address + file)
	$(call add_val_as_le_bytes,$(shell stat -c %s $<)+4) >> $@
	# load address
	$(call add_val_as_le_bytes,$(CONFIG_SYS_TEXT_BASE)) >> $@
	# image data
	dd status=noxfer if=$< >> $@ 2>/dev/null
	# make sure, the following elements are not crossing the border of a block
	# (12 bytes would be enough, but with 16 we are sure to not have
	# multiples of 512 as image size, which might be a problem for tftp boot)
	$(call pad_if_less_avail,128,16,$@)
	# TAG_START()
	$(call add_val_as_le_bytes,$(TAG_START)) >> $@
	# length (address)
	$(call add_val_as_le_bytes,4) >> $@
	# start address
	$(call add_val_as_le_bytes,$(CONFIG_SYS_TEXT_BASE)) >> $@

endif
endif
