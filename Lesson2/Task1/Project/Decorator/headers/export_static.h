
#ifndef API_DECORATOR_H
#define API_DECORATOR_H

#ifdef DECORATOR_STATIC_DEFINE
#  define API_DECORATOR
#  define DECORATOR_NO_EXPORT
#else
#  ifndef API_DECORATOR
#    ifdef Decorator_EXPORTS
        /* We are building this library */
#      define API_DECORATOR 
#    else
        /* We are using this library */
#      define API_DECORATOR 
#    endif
#  endif

#  ifndef DECORATOR_NO_EXPORT
#    define DECORATOR_NO_EXPORT 
#  endif
#endif

#ifndef DECORATOR_DEPRECATED
#  define DECORATOR_DEPRECATED __declspec(deprecated)
#endif

#ifndef DECORATOR_DEPRECATED_EXPORT
#  define DECORATOR_DEPRECATED_EXPORT API_DECORATOR DECORATOR_DEPRECATED
#endif

#ifndef DECORATOR_DEPRECATED_NO_EXPORT
#  define DECORATOR_DEPRECATED_NO_EXPORT DECORATOR_NO_EXPORT DECORATOR_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef DECORATOR_NO_DEPRECATED
#    define DECORATOR_NO_DEPRECATED
#  endif
#endif

#endif /* API_DECORATOR_H */
