#
# Copyright (C) 2014 Dog Hunter AG
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NPM_NAME=tty.js
PKG_NAME:=node-$(PKG_NPM_NAME)
PKG_VERSION:=0.2.13
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NPM_NAME)-$(PKG_VERSION).tgz
PKG_SOURCE_URL:=http://registry.nodejitsu.com/$(PKG_NPM_NAME)/-/
# PKG_MD5SUM:=5ccd4dc0a91e83aaa4bcdd9ff3b8080d

PKG_BUILD_DEPENDS:=node
PKG_NODE_VERSION:=0.10.25

include $(INCLUDE_DIR)/package.mk

define Package/node-tty.js
	DEPENDS:=+node +libc +libstdcpp
	SUBMENU:=Node.js
	SECTION:=lang
	CATEGORY:=Languages
	TITLE:=Node.js package to access serial ports for reading and writing
	URL:=https://www.npmjs.org/package/tty.js
endef

define Package/node-tty.js/description
	A terminal in your browser using node.js and socket.io. Based on Fabrice Bellard's vt100 for jslinux.
endef

define Build/Prepare
	/bin/tar xzf $(DL_DIR)/$(PKG_SOURCE) -C $(PKG_BUILD_DIR) --strip-components=1
	$(Build/Patch)
endef

define Build/Compile
	CC="$(TOOLCHAIN_DIR)/bin/mips-openwrt-linux-gcc" \
	CXX="$(TOOLCHAIN_DIR)/bin/mips-openwrt-linux-g++" \
	AR="$(TOOLCHAIN_DIR)/bin/mips-openwrt-linux-ar" \
	RANLIB="$(TOOLCHAIN_DIR)/bin/mips-openwrt-linux-ranlib" \
	LINK="$(TOOLCHAIN_DIR)/bin/mips-openwrt-linux-g++" \
	LD="$(TOOLCHAIN_DIR)/bin/mips-openwrt-linux-g++" \
	PATH="/usr/bin/:$(PATH)" \
	GYPFLAGS="-Dv8_use_mips_abi_hardfloat=false -Dv8_can_use_fpu_instructions=false" \
	LDFLAGS="-L$(TOOLCHAIN_DIR)/lib/ -Wl,-rpath-link $(TOOLCHAIN_DIR)/lib/" \
	npm_config_arch=mips \
	npm_config_nodedir=$(BUILD_DIR)/node-v$(PKG_NODE_VERSION)/ \
	PREFIX="$(PKG_INSTALL_DIR)/usr/" \
	npm install --target_arch=mips -g $(PKG_BUILD_DIR)
endef

define Package/node-tty.js/install
	$(INSTALL_DIR) $(1)/usr/lib/
	
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/node_modules $(1)/usr/lib/
endef

define Package/$(PKG_NAME)/postrm
#!/bin/sh
# check if we are on a real system
if `grep -qs '/opt' /proc/mounts`
then
	rm -rvf /opt/usr/lib/node_modules/$(PKG_NPM_NAME)
else
	rm -rvf /usr/lib/node_modules/$(PKG_NPM_NAME)
fi
endef

$(eval $(call BuildPackage,node-tty.js))
