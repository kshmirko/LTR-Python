%module ltradcapi
%{
  #define SWIG_FILE_WITH_INIT
//  #include "ltr/ltrapi_compat_defs.h"
  #include "ltr/ltrapi_config.h"
  #include "ltr/ltrapidefine.h"
  #include "ltr/ltrapitypes.h"
  #include "ltr/lwintypes.h"  
  #include "ltr/ltrapi.h"
  #include "ltr/ltr11api.h"
  #include "ltr/ltr210api.h"
%}

%include "ltr/ltrapi_compat_defs.h"
%include "ltr/ltrapi_config.h"
%include "ltr/ltrapidefine.h"
%include "ltr/ltrapitypes.h"
%include "ltr/lwintypes.h"
%include "ltr/ltrapi.h"
%include "ltr/ltr11api.h"
%include "ltr/ltr210api.h"


