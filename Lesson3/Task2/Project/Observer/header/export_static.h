
#ifndef API_OBSERVER_H
#define API_OBSERVER_H

#ifdef OBSERVER_STATIC_DEFINE
#  define API_OBSERVER
#  define OBSERVER_NO_EXPORT
#else
#  ifndef API_OBSERVER
#    ifdef Observer_EXPORTS
        /* We are building this library */
#      define API_OBSERVER 
#    else
        /* We are using this library */
#      define API_OBSERVER 
#    endif
#  endif

#  ifndef OBSERVER_NO_EXPORT
#    define OBSERVER_NO_EXPORT 
#  endif
#endif

#ifndef OBSERVER_DEPRECATED
#  define OBSERVER_DEPRECATED __declspec(deprecated)
#endif

#ifndef OBSERVER_DEPRECATED_EXPORT
#  define OBSERVER_DEPRECATED_EXPORT API_OBSERVER OBSERVER_DEPRECATED
#endif

#ifndef OBSERVER_DEPRECATED_NO_EXPORT
#  define OBSERVER_DEPRECATED_NO_EXPORT OBSERVER_NO_EXPORT OBSERVER_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef OBSERVER_NO_DEPRECATED
#    define OBSERVER_NO_DEPRECATED
#  endif
#endif

#endif /* API_OBSERVER_H */
