
#ifndef API_ERROR_HANDLERS_H
#define API_ERROR_HANDLERS_H

#ifdef ERRORHANDLERS_STATIC_DEFINE
#  define API_ERROR_HANDLERS
#  define ERRORHANDLERS_NO_EXPORT
#else
#  ifndef API_ERROR_HANDLERS
#    ifdef ErrorHandlers_EXPORTS
        /* We are building this library */
#      define API_ERROR_HANDLERS __declspec(dllexport)
#    else
        /* We are using this library */
#      define API_ERROR_HANDLERS __declspec(dllimport)
#    endif
#  endif

#  ifndef ERRORHANDLERS_NO_EXPORT
#    define ERRORHANDLERS_NO_EXPORT 
#  endif
#endif

#ifndef ERRORHANDLERS_DEPRECATED
#  define ERRORHANDLERS_DEPRECATED __declspec(deprecated)
#endif

#ifndef ERRORHANDLERS_DEPRECATED_EXPORT
#  define ERRORHANDLERS_DEPRECATED_EXPORT API_ERROR_HANDLERS ERRORHANDLERS_DEPRECATED
#endif

#ifndef ERRORHANDLERS_DEPRECATED_NO_EXPORT
#  define ERRORHANDLERS_DEPRECATED_NO_EXPORT ERRORHANDLERS_NO_EXPORT ERRORHANDLERS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ERRORHANDLERS_NO_DEPRECATED
#    define ERRORHANDLERS_NO_DEPRECATED
#  endif
#endif

#endif /* API_ERROR_HANDLERS_H */
