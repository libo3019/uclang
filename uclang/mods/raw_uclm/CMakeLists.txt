
if(PKG_CONFIG_FOUND)
  pkg_search_module(RAW "libraw")
endif()

if(RAW_FOUND)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    ${RAW_INCLUDE_DIRS})
  set(CONF_COMP_DEFS
    ${RAW_DEFINITIONS})
  set(CONF_LINK_LIBS
    base_ucll
    ${RAW_LIBRARIES})
endif()

