
if(PKG_CONFIG_FOUND)
  pkg_search_module(NANOMSG "nanomsg >= 1.1.5")
endif()

if(NANOMSG_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${NANOMSG_INCLUDE_DIRS})
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${NANOMSG_LIBRARIES})
endif()

