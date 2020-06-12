
#ifndef OTCOS_PRIVATE_HXX
#define OTCOS_PRIVATE_HXX

/* From http://gcc.gnu.org/wiki/Visibility */
/* Generic helper definitions for shared library support */
#if defined _WIN32 || defined __CYGWIN__
#define OTCOS_HELPER_DLL_IMPORT __declspec(dllimport)
#define OTCOS_HELPER_DLL_EXPORT __declspec(dllexport)
#define OTCOS_HELPER_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define OTCOS_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
#define OTCOS_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
#define OTCOS_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define OTCOS_HELPER_DLL_IMPORT
#define OTCOS_HELPER_DLL_EXPORT
#define OTCOS_HELPER_DLL_LOCAL
#endif
#endif

/* Now we use the generic helper definitions above to define OTCOS_API and OTCOS_LOCAL.
 * OTCOS_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
 * OTCOS_LOCAL is used for non-api symbols. */

#ifndef OTCOS_STATIC /* defined if OT is compiled as a DLL */
#ifdef OTCOS_DLL_EXPORTS /* defined if we are building the OT DLL (instead of using it) */
#define OTCOS_API OTCOS_HELPER_DLL_EXPORT
#else
#define OTCOS_API OTCOS_HELPER_DLL_IMPORT
#endif /* OTCOS_DLL_EXPORTS */
#define OTCOS_LOCAL OTCOS_HELPER_DLL_LOCAL
#else /* OTCOS_STATIC is defined: this means OT is a static lib. */
#define OTCOS_API
#define OTCOS_LOCAL
#endif /* !OTCOS_STATIC */


#endif // OTCOS_PRIVATE_HXX

