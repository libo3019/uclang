
set(JIT_LIBS "${EXT_LIBS}/libjit/libjit/lib")

find_library(JITPLUS_LIBRARY jitplus ${JIT_LIBS})
find_library(JITDYNAMIC_LIBRARY jitdynamic ${JIT_LIBS})
find_library(JIT_LIBRARY jit ${JIT_LIBS})

if(JITPLUS_LIBRARY AND JITDYNAMIC_LIBRARY AND JIT_LIBRARY)
  set(CONF_DO_BUILD TRUE)
  set(CONF_HEADER_DIRS
    "${LIB_BASE}/header_files")
  set(CONF_INCLUDE_DIRS
    "${EXT_LIBS}/libjit/libjit/include")
  set(CONF_COMP_DEFS)
  set(CONF_LINK_LIBS
    base_ucll
    ${JITPLUS_LIBRARY}
    ${JITDYNAMIC_LIBRARY}
    ${JIT_LIBRARY})
endif()

