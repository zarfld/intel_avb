









































#pragma once











#pragma once









#pragma once




























    







    
    


        


            
        
    
















#pragma once





















































































































































































































































































































































































































































































































































































































































































































#pragma region Input Buffer SAL 1 compatibility macros



























































































































































































































































































































































































































































































































































































































































































































































































#pragma endregion Input Buffer SAL 1 compatibility macros


































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

    
    
    
    

    
    

























































































































































































































































    
    














































































































#pragma once




































































































































































































































































































































































































#pragma once



#pragma pack(push, 8)



    


        
    





    


        
    




    





    


#pragma warning(push)
#pragma warning(disable:   4514 4820 )










    
    
        typedef unsigned __int64  uintptr_t;
    





    
    


        typedef char* va_list;
    





    











    
    






























































    void __cdecl __va_start(va_list* , ...);

    
    



    








































    



#pragma warning(pop) 
#pragma pack(pop)


#pragma warning(push)
#pragma warning(disable:   4514 4820 )


























    


    




__pragma(pack(push, 8))




    


        
    

















    




        
    



    


        
    







    
    





    












    





    



    



      
    







    typedef unsigned __int64 size_t;
    typedef __int64          ptrdiff_t;
    typedef __int64          intptr_t;













    typedef _Bool __vcrt_bool;




    



    



    




    
    typedef unsigned short wchar_t;



    


        
    



    

















    













    



    


        
    



    


        
    



    


        
    














    
        
    









    










    


        
    








    










    
        
    













    
        
    






    void __cdecl __security_init_cookie(void);

    






        void __cdecl __security_check_cookie(  uintptr_t _StackCookie);
        __declspec(noreturn) void __cdecl __report_gsfailure(  uintptr_t _StackCookie);
    


extern uintptr_t __security_cookie;


    
    
    


__pragma(pack(pop))

#pragma warning(pop) 










    

















        
    



    



    
        
    




















    


        
    




    















    



    











        
    



    


        
    


#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )


__pragma(pack(push, 8))







    




        
    





    



    




        
    





    



    









    






    





    










    














    


        
    





    





    





    



    


        
    





























    typedef _Bool __crt_bool;















    
        


            
        
    




















    


        
    







    



 






  


   
  
 



 


   
 

















 void __cdecl _invalid_parameter_noinfo(void);
 __declspec(noreturn) void __cdecl _invalid_parameter_noinfo_noreturn(void);

__declspec(noreturn)
 void __cdecl _invoke_watson(
      wchar_t const* _Expression,
      wchar_t const* _FunctionName,
      wchar_t const* _FileName,
            unsigned int _LineNo,
            uintptr_t _Reserved);


    



        
        
        
        
        
        
        
        
        
        
        
        

    













    









    


        


    










    






        
    



    


        
    








































    







    





    


        


            
        
    













    


        



    



    
        
    





    
        
        
        
    





    
        
              
        


    





    
        
    





    
        
    







    









typedef int                           errno_t;
typedef unsigned short                wint_t;
typedef unsigned short                wctype_t;
typedef long                          __time32_t;
typedef __int64                       __time64_t;

typedef struct __crt_locale_data_public
{
      unsigned short const* _locale_pctype;
      int _locale_mb_cur_max;
               unsigned int _locale_lc_codepage;
} __crt_locale_data_public;

typedef struct __crt_locale_pointers
{
    struct __crt_locale_data*    locinfo;
    struct __crt_multibyte_data* mbcinfo;
} __crt_locale_pointers;

typedef __crt_locale_pointers* _locale_t;

typedef struct _Mbstatet
{ 
    unsigned long _Wchar;
    unsigned short _Byte, _State;
} _Mbstatet;

typedef _Mbstatet mbstate_t;










    


        typedef __time64_t time_t;
    




    



    typedef size_t rsize_t;











    

















































































































































        
        
        
        
        
        
        
        
        
        
        
        

    













































































    















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































        
        
        
        

        

            


            


            


            


            


            


            


            


            



            



            


            


            


            


            


            


            


            


            


            


            



            



            



            


            



            




            

            




            

            




            

            




            

            




            

            




            

            




            

            




            

        












































    


__pragma(pack(pop))


#pragma warning(pop) 











#pragma once










#pragma once



#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )


__pragma(pack(push, 8))









    



    


        
    

















    















    
















    
    
       
    
    __declspec(noinline) __inline unsigned __int64* __cdecl __local_stdio_printf_options(void)
    {
        static unsigned __int64 _OptionsStorage;
        return &_OptionsStorage;
    }

    
    
       
    
    __declspec(noinline) __inline unsigned __int64* __cdecl __local_stdio_scanf_options(void)
    {
        static unsigned __int64 _OptionsStorage;
        return &_OptionsStorage;
    }

























__pragma(pack(pop))

#pragma warning(pop) 


#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )


__pragma(pack(push, 8))







    
    typedef struct _iobuf
    {
        void* _Placeholder;
    } FILE;


 FILE* __cdecl __acrt_iob_func(unsigned _Ix);










    
    
    
    
    
    
     wint_t __cdecl fgetwc(
          FILE* _Stream
        );

    
     wint_t __cdecl _fgetwchar(void);

    
     wint_t __cdecl fputwc(
             wchar_t _Character,
          FILE*   _Stream);

    
     wint_t __cdecl _fputwchar(
          wchar_t _Character
        );

     
     wint_t __cdecl getwc(
          FILE* _Stream
        );

     
     wint_t __cdecl getwchar(void);


    
     
     wchar_t* __cdecl fgetws(
          wchar_t* _Buffer,
                                  int      _BufferCount,
                               FILE*    _Stream
        );

    
     int __cdecl fputws(
           wchar_t const* _Buffer,
          FILE*          _Stream
        );

    
     
     wchar_t* __cdecl _getws_s(
          wchar_t* _Buffer,
                                  size_t   _BufferCount
        );

    

    
     wint_t __cdecl putwc(
             wchar_t _Character,
          FILE*   _Stream
        );

    
     wint_t __cdecl putwchar(
          wchar_t _Character
        );

    
     int __cdecl _putws(
          wchar_t const* _Buffer
        );

    
     wint_t __cdecl ungetwc(
             wint_t _Character,
          FILE*  _Stream
        );

     
     FILE * __cdecl _wfdopen(
            int            _FileHandle,
          wchar_t const* _Mode
        );

      
     FILE* __cdecl _wfopen(
          wchar_t const* _FileName,
          wchar_t const* _Mode
        );

    
     errno_t __cdecl _wfopen_s(
          FILE**         _Stream,
                             wchar_t const* _FileName,
                             wchar_t const* _Mode
        );

     
    
     FILE* __cdecl _wfreopen(
           wchar_t const* _FileName,
           wchar_t const* _Mode,
          FILE*          _OldStream
        );

    
     errno_t __cdecl _wfreopen_s(
          FILE**         _Stream,
                             wchar_t const* _FileName,
                             wchar_t const* _Mode,
                            FILE*          _OldStream
        );

     
     FILE* __cdecl _wfsopen(
          wchar_t const* _FileName,
          wchar_t const* _Mode,
            int            _ShFlag
        );

     void __cdecl _wperror(
          wchar_t const* _ErrorMessage
        );

    

         
         FILE* __cdecl _wpopen(
              wchar_t const* _Command,
              wchar_t const* _Mode
            );

    

     int __cdecl _wremove(
          wchar_t const* _FileName
        );

    
    

     
     __declspec(allocator) wchar_t* __cdecl _wtempnam(
          wchar_t const* _Directory,
          wchar_t const* _FilePrefix
        );

    

     
    
     errno_t __cdecl _wtmpnam_s(
          wchar_t* _Buffer,
                                  size_t   _BufferCount
        );

    

       wchar_t* __cdecl _wtmpnam(  wchar_t *_Buffer);



    
    
    
    
    
    
     wint_t __cdecl _fgetwc_nolock(
          FILE* _Stream
        );

    
     wint_t __cdecl _fputwc_nolock(
             wchar_t _Character,
          FILE*   _Stream
        );

    
     wint_t __cdecl _getwc_nolock(
          FILE* _Stream
        );

    
     wint_t __cdecl _putwc_nolock(
             wchar_t _Character,
          FILE*   _Stream
        );

    
     wint_t __cdecl _ungetwc_nolock(
             wint_t _Character,
          FILE*  _Stream
        );

    







    
    





    
    
    
    
    
    
     int __cdecl __stdio_common_vfwprintf(
                                             unsigned __int64 _Options,
                                          FILE*            _Stream,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

    
     int __cdecl __stdio_common_vfwprintf_s(
                                             unsigned __int64 _Options,
                                          FILE*            _Stream,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

    
     int __cdecl __stdio_common_vfwprintf_p(
                                             unsigned __int64 _Options,
                                          FILE*            _Stream,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

    
    __inline int __cdecl _vfwprintf_l(
                                          FILE*          const _Stream,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    


    {
        return __stdio_common_vfwprintf((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
    }
    

    
    __inline int __cdecl vfwprintf(
                                FILE*          const _Stream,
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    


    {
        return _vfwprintf_l(_Stream, _Format, ((void *)0), _ArgList);
    }
    

    
    __inline int __cdecl _vfwprintf_s_l(
                                          FILE*          const _Stream,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    


    {
        return __stdio_common_vfwprintf_s((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
    }
    

    

        
        __inline int __cdecl vfwprintf_s(
                                    FILE*          const _Stream,
                wchar_t const* const _Format,
                                          va_list              _ArgList
            )
    


        {
            return _vfwprintf_s_l(_Stream, _Format, ((void *)0), _ArgList);
        }
    

    

    
    __inline int __cdecl _vfwprintf_p_l(
                                          FILE*          const _Stream,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    


    {
        return __stdio_common_vfwprintf_p((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
    }
    

    
    __inline int __cdecl _vfwprintf_p(
                                FILE*          const _Stream,
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    


    {
        return _vfwprintf_p_l(_Stream, _Format, ((void *)0), _ArgList);
    }
    

    
    __inline int __cdecl _vwprintf_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    


    {
        return _vfwprintf_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
    }
    

    
    __inline int __cdecl vwprintf(
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    


    {
        return _vfwprintf_l((__acrt_iob_func(1)), _Format, ((void *)0), _ArgList);
    }
    

    
    __inline int __cdecl _vwprintf_s_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    


    {
        return _vfwprintf_s_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
    }
    

    

        
        __inline int __cdecl vwprintf_s(
                wchar_t const* const _Format,
                                          va_list              _ArgList
            )
    


        {
            return _vfwprintf_s_l((__acrt_iob_func(1)), _Format, ((void *)0), _ArgList);
        }
    

    

    
    __inline int __cdecl _vwprintf_p_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    


    {
        return _vfwprintf_p_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
    }
    

    
    __inline int __cdecl _vwprintf_p(
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    


    {
        return _vfwprintf_p_l((__acrt_iob_func(1)), _Format, ((void *)0), _ArgList);
    }
    

    
    __inline int __cdecl _fwprintf_l(
                                          FILE*          const _Stream,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfwprintf_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl fwprintf(
                                FILE*          const _Stream,
            wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vfwprintf_l(_Stream, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _fwprintf_s_l(
                                          FILE*          const _Stream,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfwprintf_s_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    

        
        __inline int __cdecl fwprintf_s(
                                    FILE*          const _Stream,
                wchar_t const* const _Format,
            ...)
    


        {
            int _Result;
            va_list _ArgList;
            ((void)(__va_start(&_ArgList, _Format)));
            _Result = _vfwprintf_s_l(_Stream, _Format, ((void *)0), _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }
    

    

    
    __inline int __cdecl _fwprintf_p_l(
                                          FILE*          const _Stream,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfwprintf_p_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _fwprintf_p(
                                FILE*          const _Stream,
            wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vfwprintf_p_l(_Stream, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _wprintf_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfwprintf_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl wprintf(
            wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vfwprintf_l((__acrt_iob_func(1)), _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _wprintf_s_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfwprintf_s_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    

        
        __inline int __cdecl wprintf_s(
                wchar_t const* const _Format,
            ...)
    


        {
            int _Result;
            va_list _ArgList;
            ((void)(__va_start(&_ArgList, _Format)));
            _Result = _vfwprintf_s_l((__acrt_iob_func(1)), _Format, ((void *)0), _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }
    

    

    
    __inline int __cdecl _wprintf_p_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfwprintf_p_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _wprintf_p(
            wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vfwprintf_p_l((__acrt_iob_func(1)), _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    


    
    
    
    
    
    
     int __cdecl __stdio_common_vfwscanf(
                                            unsigned __int64 _Options,
                                         FILE*            _Stream,
            wchar_t const*   _Format,
                                        _locale_t        _Locale,
                                               va_list          _ArgList
        );

    
    __inline int __cdecl _vfwscanf_l(
          FILE*                                const _Stream,
            wchar_t const* const _Format,
                               _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    


    {
        return __stdio_common_vfwscanf(
            (*__local_stdio_scanf_options ()),
            _Stream, _Format, _Locale, _ArgList);
    }
    

    
    __inline int __cdecl vfwscanf(
          FILE*                                const _Stream,
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    


    {
        return _vfwscanf_l(_Stream, _Format, ((void *)0), _ArgList);
    }
    

    
    __inline int __cdecl _vfwscanf_s_l(
                                FILE*          const _Stream,
            wchar_t const* const _Format,
                               _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    


    {
        return __stdio_common_vfwscanf(
            (*__local_stdio_scanf_options ()) | (1ULL << 0),
            _Stream, _Format, _Locale, _ArgList);
    }
    

    

        
        __inline int __cdecl vfwscanf_s(
                                    FILE*          const _Stream,
                wchar_t const* const _Format,
                                          va_list              _ArgList
            )
    


        {
            return _vfwscanf_s_l(_Stream, _Format, ((void *)0), _ArgList);
        }
    

    

    __inline int __cdecl _vwscanf_l(
            wchar_t const* const _Format,
                               _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    


    {
        return _vfwscanf_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
    }
    

    
    __inline int __cdecl vwscanf(
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    


    {
        return _vfwscanf_l((__acrt_iob_func(0)), _Format, ((void *)0), _ArgList);
    }
    

    
    __inline int __cdecl _vwscanf_s_l(
            wchar_t const* const _Format,
                               _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    


    {
        return _vfwscanf_s_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
    }
    

    

        
        __inline int __cdecl vwscanf_s(
                wchar_t const* const _Format,
                                          va_list              _ArgList
            )
    


        {
            return _vfwscanf_s_l((__acrt_iob_func(0)), _Format, ((void *)0), _ArgList);
        }
    

    

     
    __inline int __cdecl _fwscanf_l(
                                         FILE*          const _Stream,
            wchar_t const* const _Format,
                                        _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfwscanf_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

      
    __inline int __cdecl fwscanf(
                               FILE*          const _Stream,
            wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vfwscanf_l(_Stream, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _fwscanf_s_l(
                                           FILE*          const _Stream,
            wchar_t const* const _Format,
                                          _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfwscanf_s_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    

        
        __inline int __cdecl fwscanf_s(
                                     FILE*          const _Stream,
                wchar_t const* const _Format,
            ...)
    


        {
            int _Result;
            va_list _ArgList;
            ((void)(__va_start(&_ArgList, _Format)));
            _Result = _vfwscanf_s_l(_Stream, _Format, ((void *)0), _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }
    

    

     
    __inline int __cdecl _wscanf_l(
            wchar_t const* const _Format,
                                        _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfwscanf_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

      
    __inline int __cdecl wscanf(
            wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vfwscanf_l((__acrt_iob_func(0)), _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _wscanf_s_l(
            wchar_t const* const _Format,
                                          _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfwscanf_s_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    

        
        __inline int __cdecl wscanf_s(
                wchar_t const* const _Format,
            ...)
    


        {
            int _Result;
            va_list _ArgList;
            ((void)(__va_start(&_ArgList, _Format)));
            _Result = _vfwscanf_s_l((__acrt_iob_func(0)), _Format, ((void *)0), _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }
    

    



    
    
    
    
    
    
        



    



     
    
     int __cdecl __stdio_common_vswprintf(
                                             unsigned __int64 _Options,
                 wchar_t*         _Buffer,
                                             size_t           _BufferCount,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
    
     int __cdecl __stdio_common_vswprintf_s(
                                             unsigned __int64 _Options,
                     wchar_t*         _Buffer,
                                             size_t           _BufferCount,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
    
     int __cdecl __stdio_common_vsnwprintf_s(
                                             unsigned __int64 _Options,
                 wchar_t*         _Buffer,
                                             size_t           _BufferCount,
                                             size_t           _MaxCount,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
    
     int __cdecl __stdio_common_vswprintf_p(
                                             unsigned __int64 _Options,
                     wchar_t*         _Buffer,
                                             size_t           _BufferCount,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
     
    __inline int __cdecl _vsnwprintf_l(
            wchar_t*       const _Buffer,
                                                  size_t         const _BufferCount,
                 wchar_t const* const _Format,
                                              _locale_t      const _Locale,
                                                     va_list              _ArgList
        )
    


    {
        int const _Result = __stdio_common_vswprintf(
            (*__local_stdio_printf_options()) | (1ULL << 0),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    

     
    
    __inline int __cdecl _vsnwprintf_s_l(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                                       size_t         const _MaxCount,
                      wchar_t const* const _Format,
                                                   _locale_t      const _Locale,
                                                          va_list              _ArgList
        )
    


    {
        int const _Result = __stdio_common_vsnwprintf_s(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    

     
    
    __inline int __cdecl _vsnwprintf_s(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                                       size_t         const _MaxCount,
                                wchar_t const* const _Format,
                                                          va_list              _ArgList
        )
    


    {
        return _vsnwprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, ((void *)0), _ArgList);
    }
    

     __inline   int __cdecl _snwprintf(    wchar_t *_Buffer,   size_t _BufferCount,     wchar_t const* _Format, ...);  __inline   int __cdecl _vsnwprintf(    wchar_t *_Buffer,   size_t _BufferCount,     wchar_t const* _Format, va_list _Args);

     
     
    __inline int __cdecl _vsnwprintf(
            wchar_t*       _Buffer,
                                                  size_t         _BufferCount,
                           wchar_t const* _Format,
                                                     va_list        _ArgList
        )
    


    {
        return _vsnwprintf_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
    }
    

    

     
    
    __inline int __cdecl _vswprintf_c_l(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                      wchar_t const* const _Format,
                                                   _locale_t      const _Locale,
                                                          va_list              _ArgList
        )
    


    {
        int const _Result = __stdio_common_vswprintf(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    

     
    
    __inline int __cdecl _vswprintf_c(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                wchar_t const* const _Format,
                                                          va_list              _ArgList
        )
    


    {
        return _vswprintf_c_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
    }
    

     
    
    __inline int __cdecl _vswprintf_l(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                      wchar_t const* const _Format,
                                                   _locale_t      const _Locale,
                                                          va_list              _ArgList
        )
    


    {
        return _vswprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
    }
    

     
    
    __inline int __cdecl __vswprintf_l(
                  wchar_t*       const _Buffer,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    


    {
        return _vswprintf_l(_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }
    

     
    
    __inline int __cdecl _vswprintf(
           wchar_t*       const _Buffer,
               wchar_t const* const _Format,
                                         va_list              _ArgList
        )
    


    {
        return _vswprintf_l(_Buffer, (size_t)-1, _Format, ((void *)0), _ArgList);
    }
    

     
    
    __inline int __cdecl vswprintf(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                      wchar_t const* const _Format,
                                                          va_list              _ArgList
        )
    


    {
        return _vswprintf_c_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
    }
    

     
    
    __inline int __cdecl _vswprintf_s_l(
           wchar_t*       const _Buffer,
                                                   size_t         const _BufferCount,
                  wchar_t const* const _Format,
                                               _locale_t      const _Locale,
                                                      va_list              _ArgList
        )
    


    {
        int const _Result = __stdio_common_vswprintf_s(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    

    

         
        __inline int __cdecl vswprintf_s(
               wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                wchar_t const* const _Format,
                                                          va_list              _ArgList
            )
    


        {
            return _vswprintf_s_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
        }
    

    

    

     
    
    __inline int __cdecl _vswprintf_p_l(
           wchar_t*       const _Buffer,
                                                   size_t         const _BufferCount,
                  wchar_t const* const _Format,
                                               _locale_t      const _Locale,
                                                      va_list              _ArgList
        )
    


    {
        int const _Result = __stdio_common_vswprintf_p(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    

     
    
    __inline int __cdecl _vswprintf_p(
           wchar_t*       const _Buffer,
                                                   size_t         const _BufferCount,
                            wchar_t const* const _Format,
                                                      va_list              _ArgList
        )
    


    {
        return _vswprintf_p_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
    }
    

     
     
    __inline int __cdecl _vscwprintf_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    


    {
        int const _Result = __stdio_common_vswprintf(
            (*__local_stdio_printf_options()) | (1ULL << 1),
            ((void *)0), 0, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    

     
     
    __inline int __cdecl _vscwprintf(
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    


    {
        return _vscwprintf_l(_Format, ((void *)0), _ArgList);
    }
    

     
     
    __inline int __cdecl _vscwprintf_p_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    


    {
        int const _Result = __stdio_common_vswprintf_p(
            (*__local_stdio_printf_options()) | (1ULL << 1),
            ((void *)0), 0, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    

     
     
    __inline int __cdecl _vscwprintf_p(
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    


    {
        return _vscwprintf_p_l(_Format, ((void *)0), _ArgList);
    }
    

     
    
    __inline int __cdecl __swprintf_l(
                  wchar_t*       const _Buffer,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = __vswprintf_l(_Buffer, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _swprintf_l(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                      wchar_t const* const _Format,
                                                   _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vswprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _swprintf(
           wchar_t*       const _Buffer,
               wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = __vswprintf_l(_Buffer, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl swprintf(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vswprintf_c_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     __inline   int __cdecl __swprintf_l(   wchar_t *_Buffer,     wchar_t const* _Format,   _locale_t _Locale, ...);  __inline   int __cdecl __vswprintf_l(   wchar_t *_Buffer,     wchar_t const* _Format,   _locale_t _Locale, va_list _Args);

     __inline   int __cdecl _swprintf(   wchar_t *_Buffer,     wchar_t const* _Format, ...);  __inline   int __cdecl _vswprintf(   wchar_t *_Buffer,     wchar_t const* _Format, va_list _Args);

     
    
    __inline int __cdecl _swprintf_s_l(
           wchar_t*       const _Buffer,
                                                   size_t         const _BufferCount,
                  wchar_t const* const _Format,
                                               _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vswprintf_s_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    

         
        __inline int __cdecl swprintf_s(
               wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                wchar_t const* const _Format,
            ...)
    


        {
            int _Result;
            va_list _ArgList;
            ((void)(__va_start(&_ArgList, _Format)));
            _Result = _vswprintf_s_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }
    

    

    

     
    
    __inline int __cdecl _swprintf_p_l(
           wchar_t*       const _Buffer,
                                                   size_t         const _BufferCount,
                  wchar_t const* const _Format,
                                               _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vswprintf_p_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _swprintf_p(
           wchar_t*       const _Buffer,
                                                   size_t         const _BufferCount,
                            wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vswprintf_p_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _swprintf_c_l(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                      wchar_t const* const _Format,
                                                   _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vswprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _swprintf_c(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vswprintf_c_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
     
    __inline int __cdecl _snwprintf_l(
            wchar_t*       const _Buffer,
                                                  size_t         const _BufferCount,
                 wchar_t const* const _Format,
                                              _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));

        _Result = _vsnwprintf_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _snwprintf(
            wchar_t*       _Buffer,
                                                  size_t         _BufferCount,
                           wchar_t const* _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));

        _Result = _vsnwprintf_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _snwprintf_s_l(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                                       size_t         const _MaxCount,
                      wchar_t const* const _Format,
                                                   _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vsnwprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _snwprintf_s(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                                       size_t         const _MaxCount,
                                wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vsnwprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    

     
    __inline int __cdecl _scwprintf_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vscwprintf_l(_Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
     
    __inline int __cdecl _scwprintf(
            wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vscwprintf_l(_Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
     
    __inline int __cdecl _scwprintf_p_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vscwprintf_p_l(_Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
     
    __inline int __cdecl _scwprintf_p(
            wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vscwprintf_p_l(_Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    


    
        
        
        #pragma warning(push)
        #pragma warning(disable: 4141 6054)

        





















































        #pragma warning(pop)
    

    







    
    
    
    
    
     
     int __cdecl __stdio_common_vswscanf(
                                            unsigned __int64 _Options,
                  wchar_t const*   _Buffer,
                                            size_t           _BufferCount,
            wchar_t const*   _Format,
                                        _locale_t        _Locale,
                                               va_list          _ArgList
        );

     
    
    __inline int __cdecl _vswscanf_l(
                                 wchar_t const* const _Buffer,
            wchar_t const* const _Format,
                               _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    


    {
        return __stdio_common_vswscanf(
            (*__local_stdio_scanf_options ()),
            _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }
    

     
    
    __inline int __cdecl vswscanf(
                                 wchar_t const* _Buffer,
            wchar_t const* _Format,
                                      va_list        _ArgList
        )
    


    {
        return _vswscanf_l(_Buffer, _Format, ((void *)0), _ArgList);
    }
    

     
    
    __inline int __cdecl _vswscanf_s_l(
                                 wchar_t const* const _Buffer,
            wchar_t const* const _Format,
                               _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    


    {
        return __stdio_common_vswscanf(
            (*__local_stdio_scanf_options ()) | (1ULL << 0),
            _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }
    

    

         
        
        __inline int __cdecl vswscanf_s(
                                     wchar_t const* const _Buffer,
                wchar_t const* const _Format,
                                          va_list              _ArgList
            )
    


        {
            return _vswscanf_s_l(_Buffer, _Format, ((void *)0), _ArgList);
        }
    

    

    

     
     
    __inline int __cdecl _vsnwscanf_l(
                  wchar_t const* const _Buffer,
                                            size_t         const _BufferCount,
            wchar_t const* const _Format,
                                        _locale_t      const _Locale,
                                               va_list              _ArgList
        )
    


    {
        return __stdio_common_vswscanf(
            (*__local_stdio_scanf_options ()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    }
    

     
    
    __inline int __cdecl _vsnwscanf_s_l(
                    wchar_t const* const _Buffer,
                                              size_t         const _BufferCount,
            wchar_t const* const _Format,
                                          _locale_t      const _Locale,
                                                 va_list              _ArgList
        )
    


    {
        return __stdio_common_vswscanf(
            (*__local_stdio_scanf_options ()) | (1ULL << 0),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    }
    

     
     
    __inline int __cdecl _swscanf_l(
                                          wchar_t const* const _Buffer,
            wchar_t const* const _Format,
                                        _locale_t            _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vswscanf_l(_Buffer, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
      
    __inline int __cdecl swscanf(
                                wchar_t const* const _Buffer,
            wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vswscanf_l(_Buffer, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _swscanf_s_l(
                                            wchar_t const* const _Buffer,
            wchar_t const* const _Format,
                                          _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vswscanf_s_l(_Buffer, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    

         
        
        __inline int __cdecl swscanf_s(
                                      wchar_t const* const _Buffer,
                wchar_t const* const _Format,
            ...)
    


        {
            int _Result;
            va_list _ArgList;
            ((void)(__va_start(&_ArgList, _Format)));
            _Result = _vswscanf_s_l(_Buffer, _Format, ((void *)0), _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }
    

    

     
     
    __inline int __cdecl _snwscanf_l(
                  wchar_t const* const _Buffer,
                                            size_t         const _BufferCount,
            wchar_t const* const _Format,
                                        _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));

        _Result = _vsnwscanf_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
     
    __inline int __cdecl _snwscanf(
            wchar_t const* const _Buffer,
                                      size_t         const _BufferCount,
                wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));

        _Result = _vsnwscanf_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _snwscanf_s_l(
                    wchar_t const* const _Buffer,
                                              size_t         const _BufferCount,
            wchar_t const* const _Format,
                                          _locale_t      const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vsnwscanf_s_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _snwscanf_s(
             wchar_t const* const _Buffer,
                                       size_t         const _BufferCount,
               wchar_t const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vsnwscanf_s_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    




__pragma(pack(pop))

#pragma warning(pop) 


#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )


__pragma(pack(push, 8))































    
















    
    



typedef __int64 fpos_t;





    
     errno_t __cdecl _get_stream_buffer_pointers(
               FILE*   _Stream,
          char*** _Base,
          char*** _Pointer,
          int**   _Count
        );


    
    
    
    
    
    

        
         errno_t __cdecl clearerr_s(
              FILE* _Stream
            );

        
         
         errno_t __cdecl fopen_s(
              FILE**      _Stream,
                                     char const* _FileName,
                                     char const* _Mode
            );

        
         
         size_t __cdecl fread_s(
                void*  _Buffer,
                                    size_t _BufferSize,
                                                                            size_t _ElementSize,
                                                                            size_t _ElementCount,
                                                                         FILE*  _Stream
            );

        
         errno_t __cdecl freopen_s(
              FILE**      _Stream,
                                 char const* _FileName,
                                 char const* _Mode,
                                FILE*       _OldStream
            );

         
         char* __cdecl gets_s(
              char*   _Buffer,
                               rsize_t _Size
            );

        
         errno_t __cdecl tmpfile_s(
                FILE** _Stream
            );

         
        
         errno_t __cdecl tmpnam_s(
              char*   _Buffer,
                               rsize_t _Size
            );

    

     void __cdecl clearerr(
          FILE* _Stream
        );

     
    
     int __cdecl fclose(
          FILE* _Stream
        );

    
     int __cdecl _fcloseall(void);

     
     FILE* __cdecl _fdopen(
            int         _FileHandle,
          char const* _Mode
        );

     
     int __cdecl feof(
          FILE* _Stream
        );

     
     int __cdecl ferror(
          FILE* _Stream
        );

    
     int __cdecl fflush(
          FILE* _Stream
        );

     
    
     int __cdecl fgetc(
          FILE* _Stream
        );

    
     int __cdecl _fgetchar(void);

     
    
     int __cdecl fgetpos(
          FILE*   _Stream,
            fpos_t* _Position
        );

     
    
     char* __cdecl fgets(
          char* _Buffer,
                               int   _MaxCount,
                            FILE* _Stream
        );

     
     int __cdecl _fileno(
          FILE* _Stream
        );

    
     int __cdecl _flushall(void);

      
     FILE* __cdecl fopen(
          char const* _FileName,
          char const* _Mode
        );


     
    
     int __cdecl fputc(
             int   _Character,
          FILE* _Stream
        );

    
     int __cdecl _fputchar(
          int _Character
        );

     
    
     int __cdecl fputs(
           char const* _Buffer,
          FILE*       _Stream
        );

    
     size_t __cdecl fread(
          void*  _Buffer,
                                                      size_t _ElementSize,
                                                      size_t _ElementCount,
                                                   FILE*  _Stream
        );

     
      
     FILE* __cdecl freopen(
           char const* _FileName,
           char const* _Mode,
          FILE*       _Stream
        );

     
     FILE* __cdecl _fsopen(
          char const* _FileName,
          char const* _Mode,
            int         _ShFlag
        );

     
    
     int __cdecl fsetpos(
          FILE*         _Stream,
             fpos_t const* _Position
        );

     
    
     int __cdecl fseek(
          FILE* _Stream,
             long  _Offset,
             int   _Origin
        );

     
    
     int __cdecl _fseeki64(
          FILE*   _Stream,
             __int64 _Offset,
             int     _Origin
        );

     
     
     long __cdecl ftell(
          FILE* _Stream
        );

     
     
     __int64 __cdecl _ftelli64(
          FILE* _Stream
        );

    
     size_t __cdecl fwrite(
          void const* _Buffer,
                                                    size_t      _ElementSize,
                                                    size_t      _ElementCount,
                                                 FILE*       _Stream
        );

     
     
     int __cdecl getc(
          FILE* _Stream
        );

     
     int __cdecl getchar(void);

     
     int __cdecl _getmaxstdio(void);

    

     
     int __cdecl _getw(
          FILE* _Stream
        );

     void __cdecl perror(
          char const* _ErrorMessage
        );

    

         
        
         int __cdecl _pclose(
              FILE* _Stream
            );

         
         FILE* __cdecl _popen(
              char const* _Command,
              char const* _Mode
            );

    

     
    
     int __cdecl putc(
             int   _Character,
          FILE* _Stream
        );

    
     int __cdecl putchar(
          int _Character
        );

    
     int __cdecl puts(
          char const* _Buffer
        );

     
    
     int __cdecl _putw(
             int   _Word,
          FILE* _Stream
        );

     int __cdecl remove(
          char const* _FileName
        );

     
     int __cdecl rename(
          char const* _OldFileName,
          char const* _NewFileName
        );

     int __cdecl _unlink(
          char const* _FileName
        );

    

        __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_unlink" ". See online help for details."))
         int __cdecl unlink(
              char const* _FileName
            );

    

     void __cdecl rewind(
          FILE* _Stream
        );

    
     int __cdecl _rmtmp(void);

    
     void __cdecl setbuf(
                                                      FILE* _Stream,
            char* _Buffer
        );

    
     int __cdecl _setmaxstdio(
          int _Maximum
        );

     
    
     int __cdecl setvbuf(
                               FILE*  _Stream,
            char*  _Buffer,
                                  int    _Mode,
                                  size_t _Size
        );

    




     
     __declspec(allocator) char* __cdecl _tempnam(
          char const* _DirectoryName,
          char const* _FilePrefix
        );

    



      
     FILE* __cdecl tmpfile(void);

    

   char* __cdecl tmpnam(  char *_Buffer);

     
    
     int __cdecl ungetc(
             int   _Character,
          FILE* _Stream
        );



    
    
    
    
    
     void __cdecl _lock_file(
          FILE* _Stream
        );

     void __cdecl _unlock_file(
          FILE* _Stream
        );

     
    
     int __cdecl _fclose_nolock(
          FILE* _Stream
        );

     
    
     int __cdecl _fflush_nolock(
          FILE* _Stream
        );

     
    
     int __cdecl _fgetc_nolock(
          FILE* _Stream
        );

     
    
     int __cdecl _fputc_nolock(
             int   _Character,
          FILE* _Stream
        );

    
     size_t __cdecl _fread_nolock(
          void*  _Buffer,
                                                      size_t _ElementSize,
                                                      size_t _ElementCount,
                                                   FILE*  _Stream
        );

    
     
     size_t __cdecl _fread_nolock_s(
          void*  _Buffer,
                              size_t _BufferSize,
                                                                      size_t _ElementSize,
                                                                      size_t _ElementCount,
                                                                   FILE*  _Stream
        );

    
     int __cdecl _fseek_nolock(
          FILE* _Stream,
             long  _Offset,
             int   _Origin
        );

    
     int __cdecl _fseeki64_nolock(
          FILE*   _Stream,
             __int64 _Offset,
             int     _Origin
        );

     
     long __cdecl _ftell_nolock(
          FILE* _Stream
        );

     
     __int64 __cdecl _ftelli64_nolock(
          FILE* _Stream
        );

    
     size_t __cdecl _fwrite_nolock(
          void const* _Buffer,
                                                    size_t      _ElementSize,
                                                    size_t      _ElementCount,
                                                 FILE*       _Stream
        );

    
     int __cdecl _getc_nolock(
          FILE* _Stream
        );

    
     int __cdecl _putc_nolock(
             int   _Character,
          FILE* _Stream
        );

    
     int __cdecl _ungetc_nolock(
             int   _Character,
          FILE* _Stream
        );

    
    
    
    



    


















     int* __cdecl __p__commode(void);

    


        
    



    
    



    
    
    
    
    
     int __cdecl __stdio_common_vfprintf(
                                             unsigned __int64 _Options,
                                          FILE*            _Stream,
            char const*      _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     int __cdecl __stdio_common_vfprintf_s(
                                             unsigned __int64 _Options,
                                          FILE*            _Stream,
            char const*      _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
     int __cdecl __stdio_common_vfprintf_p(
                                             unsigned __int64 _Options,
                                          FILE*            _Stream,
            char const*      _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

    
    __inline int __cdecl _vfprintf_l(
           FILE*       const _Stream,
            char const* const _Format,
          _locale_t   const _Locale,
                 va_list           _ArgList
        )
    


    {
        return __stdio_common_vfprintf((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
    }
    

    
    __inline int __cdecl vfprintf(
                                FILE*       const _Stream,
            char const* const _Format,
                                      va_list           _ArgList
        )
    


    {
        return _vfprintf_l(_Stream, _Format, ((void *)0), _ArgList);
    }
    

    
    __inline int __cdecl _vfprintf_s_l(
           FILE*       const _Stream,
            char const* const _Format,
          _locale_t   const _Locale,
                 va_list           _ArgList
        )
    


    {
        return __stdio_common_vfprintf_s((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
    }
    

    

        
        __inline int __cdecl vfprintf_s(
                                    FILE*       const _Stream,
                char const* const _Format,
                                          va_list           _ArgList
            )
    


        {
            return _vfprintf_s_l(_Stream, _Format, ((void *)0), _ArgList);
        }
    

    

    
    __inline int __cdecl _vfprintf_p_l(
           FILE*       const _Stream,
            char const* const _Format,
          _locale_t   const _Locale,
                 va_list           _ArgList
        )
    


    {
        return __stdio_common_vfprintf_p((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
    }
    

    
    __inline int __cdecl _vfprintf_p(
                                FILE*       const _Stream,
            char const* const _Format,
                                      va_list           _ArgList
        )
    


    {
        return _vfprintf_p_l(_Stream, _Format, ((void *)0), _ArgList);
    }
    

    
    __inline int __cdecl _vprintf_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    


    {
        return _vfprintf_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
    }
    

    
    __inline int __cdecl vprintf(
            char const* const _Format,
                                      va_list           _ArgList
        )
    


    {
        return _vfprintf_l((__acrt_iob_func(1)), _Format, ((void *)0), _ArgList);
    }
    

    
    __inline int __cdecl _vprintf_s_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    


    {
        return _vfprintf_s_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
    }
    

    

        
        __inline int __cdecl vprintf_s(
                char const* const _Format,
                                          va_list           _ArgList
            )
    


        {
            return _vfprintf_s_l((__acrt_iob_func(1)), _Format, ((void *)0), _ArgList);
        }
    

    

    
    __inline int __cdecl _vprintf_p_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    


    {
        return _vfprintf_p_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
    }
    

    
    __inline int __cdecl _vprintf_p(
            char const* const _Format,
                                      va_list           _ArgList
        )
    


    {
        return _vfprintf_p_l((__acrt_iob_func(1)), _Format, ((void *)0), _ArgList);
    }
    

    
    __inline int __cdecl _fprintf_l(
                                          FILE*       const _Stream,
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfprintf_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl fprintf(
                                FILE*       const _Stream,
            char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vfprintf_l(_Stream, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     int __cdecl _set_printf_count_output(
          int _Value
        );

     int __cdecl _get_printf_count_output(void);

    
    __inline int __cdecl _fprintf_s_l(
                                          FILE*       const _Stream,
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfprintf_s_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    

        
        __inline int __cdecl fprintf_s(
                                    FILE*       const _Stream,
                char const* const _Format,
            ...)
    


        {
            int _Result;
            va_list _ArgList;
            ((void)(__va_start(&_ArgList, _Format)));
            _Result = _vfprintf_s_l(_Stream, _Format, ((void *)0), _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }
    

    

    
    __inline int __cdecl _fprintf_p_l(
                                          FILE*       const _Stream,
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfprintf_p_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _fprintf_p(
                                FILE*       const _Stream,
            char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vfprintf_p_l(_Stream, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _printf_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfprintf_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl printf(
            char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vfprintf_l((__acrt_iob_func(1)), _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _printf_s_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfprintf_s_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    

        
        __inline int __cdecl printf_s(
                char const* const _Format,
            ...)
    


        {
            int _Result;
            va_list _ArgList;
            ((void)(__va_start(&_ArgList, _Format)));
            _Result = _vfprintf_s_l((__acrt_iob_func(1)), _Format, ((void *)0), _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }
    

    

    
    __inline int __cdecl _printf_p_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfprintf_p_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _printf_p(
            char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vfprintf_p_l((__acrt_iob_func(1)), _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    


    
    
    
    
    
     int __cdecl __stdio_common_vfscanf(
                                            unsigned __int64 _Options,
                                         FILE*            _Stream,
            char const*      _Format,
                                        _locale_t        _Locale,
                                               va_list          _Arglist
        );

    
    __inline int __cdecl _vfscanf_l(
                                FILE*       const _Stream,
            char const* const _Format,
                               _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    


    {
        return __stdio_common_vfscanf(
            (*__local_stdio_scanf_options ()),
            _Stream, _Format, _Locale, _ArgList);
    }
    

    
    __inline int __cdecl vfscanf(
                                FILE*       const _Stream,
            char const* const _Format,
                                      va_list           _ArgList
        )
    


    {
        return _vfscanf_l(_Stream, _Format, ((void *)0), _ArgList);
    }
    

    
    __inline int __cdecl _vfscanf_s_l(
                                FILE*       const _Stream,
            char const* const _Format,
                               _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    


    {
        return __stdio_common_vfscanf(
            (*__local_stdio_scanf_options ()) | (1ULL << 0),
            _Stream, _Format, _Locale, _ArgList);
    }
    


    

        
        __inline int __cdecl vfscanf_s(
                                    FILE*       const _Stream,
                char const* const _Format,
                                          va_list           _ArgList
            )
    


        {
            return _vfscanf_s_l(_Stream, _Format, ((void *)0), _ArgList);
        }
    

    

    
    __inline int __cdecl _vscanf_l(
            char const* const _Format,
                               _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    


    {
        return _vfscanf_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
    }
    

    
    __inline int __cdecl vscanf(
            char const* const _Format,
                                      va_list           _ArgList
        )
    


    {
        return _vfscanf_l((__acrt_iob_func(0)), _Format, ((void *)0), _ArgList);
    }
    

    
    __inline int __cdecl _vscanf_s_l(
            char const* const _Format,
                               _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    


    {
        return _vfscanf_s_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
    }
    

    

        
        __inline int __cdecl vscanf_s(
                char const* const _Format,
                                          va_list           _ArgList
            )
    


        {
            return _vfscanf_s_l((__acrt_iob_func(0)), _Format, ((void *)0), _ArgList);
        }
    

    

     
    __inline int __cdecl _fscanf_l(
                                         FILE*       const _Stream,
            char const* const _Format,
                                        _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfscanf_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

      
    __inline int __cdecl fscanf(
                               FILE*       const _Stream,
            char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vfscanf_l(_Stream, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _fscanf_s_l(
                                           FILE*       const _Stream,
            char const* const _Format,
                                          _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfscanf_s_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    

        
        __inline int __cdecl fscanf_s(
                                     FILE*       const _Stream,
                char const* const _Format,
            ...)
    


        {
            int _Result;
            va_list _ArgList;
            ((void)(__va_start(&_ArgList, _Format)));
            _Result = _vfscanf_s_l(_Stream, _Format, ((void *)0), _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }
    

    

     
    __inline int __cdecl _scanf_l(
            char const* const _Format,
                                        _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfscanf_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

      
    __inline int __cdecl scanf(
            char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vfscanf_l((__acrt_iob_func(0)), _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _scanf_s_l(
            char const* const _Format,
                                          _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vfscanf_s_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    

        
        __inline int __cdecl scanf_s(
                char const* const _Format,
            ...)
    


        {
            int _Result;
            va_list _ArgList;
            ((void)(__va_start(&_ArgList, _Format)));
            _Result = _vfscanf_s_l((__acrt_iob_func(0)), _Format, ((void *)0), _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }
    

    



    
    
    
    
    
     
     int __cdecl __stdio_common_vsprintf(
                                             unsigned __int64 _Options,
                 char*            _Buffer,
                                             size_t           _BufferCount,
            char const*      _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
     int __cdecl __stdio_common_vsprintf_s(
                                             unsigned __int64 _Options,
                     char*            _Buffer,
                                             size_t           _BufferCount,
            char const*      _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
     int __cdecl __stdio_common_vsnprintf_s(
                                             unsigned __int64 _Options,
                 char*            _Buffer,
                                             size_t           _BufferCount,
                                             size_t           _MaxCount,
            char const*      _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
     int __cdecl __stdio_common_vsprintf_p(
                                             unsigned __int64 _Options,
                     char*            _Buffer,
                                             size_t           _BufferCount,
            char const*      _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
     
    __inline int __cdecl _vsnprintf_l(
            char*       const _Buffer,
                                                  size_t      const _BufferCount,
                 char const* const _Format,
                                              _locale_t   const _Locale,
                                                     va_list           _ArgList
        )
    


    {
        int const _Result = __stdio_common_vsprintf(
            (*__local_stdio_printf_options()) | (1ULL << 0),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    

     
    
    __inline int __cdecl _vsnprintf(
            char*       const _Buffer,
                                                 size_t      const _BufferCount,
                          char const* const _Format,
                                                    va_list           _ArgList
        )
    


    {
        return _vsnprintf_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
    }
    

    










     
    
    __inline int __cdecl vsnprintf(
           char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                char const* const _Format,
                                                          va_list           _ArgList
        )
    


    {
        int const _Result = __stdio_common_vsprintf(
            (*__local_stdio_printf_options()) | (1ULL << 1),
            _Buffer, _BufferCount, _Format, ((void *)0), _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    

     
     
    __inline int __cdecl _vsprintf_l(
           char*       const _Buffer,
                                    char const* const _Format,
                                  _locale_t   const _Locale,
                                         va_list           _ArgList
        )
    


    {
        return _vsnprintf_l(_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }
    

     
     
    __inline int __cdecl vsprintf(
           char*       const _Buffer,
               char const* const _Format,
                                         va_list           _ArgList
        )
    


    {
        return _vsnprintf_l(_Buffer, (size_t)-1, _Format, ((void *)0), _ArgList);
    }
    

     
    
    __inline int __cdecl _vsprintf_s_l(
           char*       const _Buffer,
                                                   size_t      const _BufferCount,
                  char const* const _Format,
                                               _locale_t   const _Locale,
                                                      va_list           _ArgList
        )
    


    {
        int const _Result = __stdio_common_vsprintf_s(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    

    

         
        
        __inline int __cdecl vsprintf_s(
               char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                char const* const _Format,
                                                          va_list           _ArgList
            )
    


        {
            return _vsprintf_s_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
        }
    

        

    

     
    
    __inline int __cdecl _vsprintf_p_l(
           char*       const _Buffer,
                                                   size_t      const _BufferCount,
                  char const* const _Format,
                                               _locale_t   const _Locale,
                                                      va_list           _ArgList
        )
    


    {
        int const _Result = __stdio_common_vsprintf_p(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    

     
    
    __inline int __cdecl _vsprintf_p(
           char*       const _Buffer,
                                                   size_t      const _BufferCount,
                            char const* const _Format,
                                                      va_list           _ArgList
        )
    


    {
        return _vsprintf_p_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
    }
    

     
    
    __inline int __cdecl _vsnprintf_s_l(
           char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                                       size_t      const _MaxCount,
                      char const* const _Format,
                                                   _locale_t   const _Locale,
                                                          va_list          _ArgList
        )
    


    {
        int const _Result = __stdio_common_vsnprintf_s(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    

     
    
    __inline int __cdecl _vsnprintf_s(
           char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                                       size_t      const _MaxCount,
                                char const* const _Format,
                                                          va_list           _ArgList
        )
    


    {
        return _vsnprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, ((void *)0), _ArgList);
    }
    

    

    

         
        
        __inline int __cdecl vsnprintf_s(
               char*       const _Buffer,
                                                           size_t      const _BufferCount,
                                                           size_t      const _MaxCount,
                                    char const* const _Format,
                                                              va_list           _ArgList
            )
    


        {
            return _vsnprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, ((void *)0), _ArgList);
        }
    

        

    

    
    __inline int __cdecl _vscprintf_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    


    {
        int const _Result = __stdio_common_vsprintf(
            (*__local_stdio_printf_options()) | (1ULL << 1),
            ((void *)0), 0, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    

     
    __inline int __cdecl _vscprintf(
            char const* const _Format,
                                      va_list           _ArgList
        )
    


    {
        return _vscprintf_l(_Format, ((void *)0), _ArgList);
    }
    

    
    __inline int __cdecl _vscprintf_p_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    


    {
        int const _Result = __stdio_common_vsprintf_p(
            (*__local_stdio_printf_options()) | (1ULL << 1),
            ((void *)0), 0, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    

     
    __inline int __cdecl _vscprintf_p(
            char const* const _Format,
                                      va_list           _ArgList
        )
    


    {
        return _vscprintf_p_l(_Format, ((void *)0), _ArgList);
    }
    

    
    __inline int __cdecl _vsnprintf_c_l(
                   char*       const _Buffer,
                                             size_t      const _BufferCount,
            char const* const _Format,
                                         _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    


    {
        int const _Result = __stdio_common_vsprintf(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    

     
    
    __inline int __cdecl _vsnprintf_c(
          char*       const _Buffer,
                                    size_t      const _BufferCount,
             char const* const _Format,
                                       va_list           _ArgList
        )
    


    {
        return _vsnprintf_c_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
    }
    

     
     
    __inline int __cdecl _sprintf_l(
                  char*       const _Buffer,
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));

        _Result = _vsprintf_l(_Buffer, _Format, _Locale, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl sprintf(
           char*       const _Buffer,
               char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));

        _Result = _vsprintf_l(_Buffer, _Format, ((void *)0), _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

       int __cdecl sprintf(  char *_Buffer,  char const* _Format, ...);    int __cdecl vsprintf(  char *_Buffer,  char const* _Format, va_list _Args);

     
    
    __inline int __cdecl _sprintf_s_l(
           char*       const _Buffer,
                                                   size_t      const _BufferCount,
                  char const* const _Format,
                                               _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vsprintf_s_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    

         
        
        __inline int __cdecl sprintf_s(
               char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                char const* const _Format,
            ...)
    


        {
            int _Result;
            va_list _ArgList;
            ((void)(__va_start(&_ArgList, _Format)));
            _Result = _vsprintf_s_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }
    

    

    

     
    
    __inline int __cdecl _sprintf_p_l(
           char*       const _Buffer,
                                                   size_t      const _BufferCount,
                  char const* const _Format,
                                               _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vsprintf_p_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _sprintf_p(
           char*       const _Buffer,
                                                   size_t      const _BufferCount,
                            char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vsprintf_p_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
     
    __inline int __cdecl _snprintf_l(
            char*       const _Buffer,
                                                  size_t      const _BufferCount,
                 char const* const _Format,
                                              _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));

        _Result = _vsnprintf_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    










     
    
    __inline int __cdecl snprintf(
           char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = vsnprintf(_Buffer, _BufferCount, _Format, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _snprintf(
            char*       const _Buffer,
                                                  size_t      const _BufferCount,
                           char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vsnprintf(_Buffer, _BufferCount, _Format, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

        int __cdecl _snprintf(    char *_Buffer,   size_t _BufferCount,     char const* _Format, ...);     int __cdecl _vsnprintf(    char *_Buffer,   size_t _BufferCount,     char const* _Format, va_list _Args);

     
    
    __inline int __cdecl _snprintf_c_l(
                   char*       const _Buffer,
                                             size_t      const _BufferCount,
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vsnprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _snprintf_c(
          char*       const _Buffer,
                                    size_t      const _BufferCount,
             char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vsnprintf_c_l(_Buffer, _BufferCount, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _snprintf_s_l(
           char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                                       size_t      const _MaxCount,
                      char const* const _Format,
                                                   _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vsnprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    
    __inline int __cdecl _snprintf_s(
           char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                                       size_t      const _MaxCount,
                                char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vsnprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    

    
    __inline int __cdecl _scprintf_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vscprintf_l(_Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    __inline int __cdecl _scprintf(
            char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vscprintf_l(_Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _scprintf_p_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vscprintf_p_l(_Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    __inline int __cdecl _scprintf_p(
            char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vscprintf_p(_Format, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    
    
    
    
     int __cdecl __stdio_common_vsscanf(
                                            unsigned __int64 _Options,
                  char const*      _Buffer,
                                            size_t           _BufferCount,
            char const*      _Format,
                                        _locale_t        _Locale,
                                               va_list          _ArgList
        );

    
    __inline int __cdecl _vsscanf_l(
                                 char const* const _Buffer,
            char const* const _Format,
                               _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    


    {
        return __stdio_common_vsscanf(
            (*__local_stdio_scanf_options ()),
            _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }
    

    
    __inline int __cdecl vsscanf(
                                 char const* const _Buffer,
            char const* const _Format,
                                      va_list           _ArgList
        )
    


    {
        return _vsscanf_l(_Buffer, _Format, ((void *)0), _ArgList);
    }
    

    
    __inline int __cdecl _vsscanf_s_l(
                                 char const* const _Buffer,
            char const* const _Format,
                               _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    


    {
        return __stdio_common_vsscanf(
            (*__local_stdio_scanf_options ()) | (1ULL << 0),
            _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }
    

    

        #pragma warning(push)
        #pragma warning(disable: 6530) 

        
        __inline int __cdecl vsscanf_s(
                                     char const* const _Buffer,
                char const* const _Format,
                                          va_list           _ArgList
            )
    


        {
            return _vsscanf_s_l(_Buffer, _Format, ((void *)0), _ArgList);
        }
    

        

        #pragma warning(pop)

    

     
    __inline int __cdecl _sscanf_l(
                                          char const* const _Buffer,
            char const* const _Format,
                                        _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vsscanf_l(_Buffer, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

      
    __inline int __cdecl sscanf(
                                char const* const _Buffer,
            char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));
        _Result = _vsscanf_l(_Buffer, _Format, ((void *)0), _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _sscanf_s_l(
                                            char const* const _Buffer,
            char const* const _Format,
                                          _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));
        _Result = _vsscanf_s_l(_Buffer, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    

        
        __inline int __cdecl sscanf_s(
                                      char const* const _Buffer,
                char const* const _Format,
            ...)
    


        {
            int _Result;
            va_list _ArgList;
            ((void)(__va_start(&_ArgList, _Format)));

            _Result = vsscanf_s(_Buffer, _Format, _ArgList);

            ((void)(_ArgList = (va_list)0));
            return _Result;
        }
    

    

    #pragma warning(push)
    #pragma warning(disable: 6530) 

     
    __inline int __cdecl _snscanf_l(
            char const* const _Buffer,
                                            size_t      const _BufferCount,
            char const* const _Format,
                                        _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));

        _Result = __stdio_common_vsscanf(
            (*__local_stdio_scanf_options ()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

     
    __inline int __cdecl _snscanf(
            char const* const _Buffer,
                                            size_t      const _BufferCount,
                      char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));

        _Result = __stdio_common_vsscanf(
            (*__local_stdio_scanf_options ()),
            _Buffer, _BufferCount, _Format, ((void *)0), _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    


    
    __inline int __cdecl _snscanf_s_l(
              char const* const _Buffer,
                                              size_t      const _BufferCount,
            char const* const _Format,
                                          _locale_t   const _Locale,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Locale)));

        _Result = __stdio_common_vsscanf(
            (*__local_stdio_scanf_options ()) | (1ULL << 0),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    
    __inline int __cdecl _snscanf_s(
            char const* const _Buffer,
                                            size_t      const _BufferCount,
                    char const* const _Format,
        ...)
    


    {
        int _Result;
        va_list _ArgList;
        ((void)(__va_start(&_ArgList, _Format)));

        _Result = __stdio_common_vsscanf(
            (*__local_stdio_scanf_options ()) | (1ULL << 0),
            _Buffer, _BufferCount, _Format, ((void *)0), _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }
    

    #pragma warning(pop)

    





    
    
    
    
    
    

        

        




        __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_tempnam" ". See online help for details."))
         char* __cdecl tempnam(
              char const* _Directory,
              char const* _FilePrefix
            );

        



         __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_fcloseall" ". See online help for details."))  int   __cdecl fcloseall(void);
              __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_fdopen" ". See online help for details."))     FILE* __cdecl fdopen(  int _FileHandle,   char const* _Format);
         __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_fgetchar" ". See online help for details."))   int   __cdecl fgetchar(void);
              __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_fileno" ". See online help for details."))     int   __cdecl fileno(  FILE* _Stream);
         __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_flushall" ". See online help for details."))   int   __cdecl flushall(void);
         __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_fputchar" ". See online help for details."))   int   __cdecl fputchar(  int _Ch);
              __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_getw" ". See online help for details."))       int   __cdecl getw(  FILE* _Stream);
         __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_putw" ". See online help for details."))       int   __cdecl putw(  int _Ch,   FILE* _Stream);
              __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_rmtmp" ". See online help for details."))      int   __cdecl rmtmp(void);

    




__pragma(pack(pop))

#pragma warning(pop) 










#pragma once













#pragma once



#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )


__pragma(pack(push, 8))







































     
 __declspec(allocator) __declspec(restrict)
void* __cdecl _calloc_base(
      size_t _Count,
      size_t _Size
    );

     
  __declspec(allocator) __declspec(restrict) 
void* __cdecl calloc(
       size_t _Count,
       size_t _Size
    );

 
 int __cdecl _callnewh(
      size_t _Size
    );

     
 __declspec(allocator) 
void* __cdecl _expand(
                void*  _Block,
       size_t _Size
    );


void __cdecl _free_base(
        void* _Block
    );

 
void __cdecl free(
        void* _Block
    );

     
 __declspec(allocator) __declspec(restrict)
void* __cdecl _malloc_base(
      size_t _Size
    );

     
 __declspec(allocator)  __declspec(restrict) 
void* __cdecl malloc(
       size_t _Size
    );

 

size_t __cdecl _msize_base(
      void* _Block
    ) ;

 
 
size_t __cdecl _msize(
      void* _Block
    );

       
 __declspec(allocator) __declspec(restrict)
void* __cdecl _realloc_base(
         void*  _Block,
                                 size_t _Size
    );

       
 __declspec(allocator) __declspec(restrict) 
void* __cdecl realloc(
        void*  _Block,
              size_t _Size
    );

       
 __declspec(allocator) __declspec(restrict)
void* __cdecl _recalloc_base(
        void*  _Block,
                                size_t _Count,
                                size_t _Size
    );

       
 __declspec(allocator) __declspec(restrict)
void* __cdecl _recalloc(
        void*  _Block,
              size_t _Count,
              size_t _Size
    );


void __cdecl _aligned_free(
        void* _Block
    );

     
 __declspec(allocator) __declspec(restrict)
void* __cdecl _aligned_malloc(
       size_t _Size,
                         size_t _Alignment
    );

     
 __declspec(allocator) __declspec(restrict)
void* __cdecl _aligned_offset_malloc(
       size_t _Size,
                         size_t _Alignment,
                         size_t _Offset
    );

 

size_t __cdecl _aligned_msize(
      void*  _Block,
               size_t _Alignment,
               size_t _Offset
    );

       
 __declspec(allocator) __declspec(restrict)
void* __cdecl _aligned_offset_realloc(
        void*  _Block,
              size_t _Size,
                                size_t _Alignment,
                                size_t _Offset
    );

       
 __declspec(allocator) __declspec(restrict)
void* __cdecl _aligned_offset_recalloc(
        void*  _Block,
              size_t _Count,
              size_t _Size,
                                size_t _Alignment,
                                size_t _Offset
    );

       
 __declspec(allocator) __declspec(restrict)
void* __cdecl _aligned_realloc(
        void*  _Block,
              size_t _Size,
                                size_t _Alignment
    );

       
 __declspec(allocator) __declspec(restrict)
void* __cdecl _aligned_recalloc(
        void*  _Block,
              size_t _Count,
              size_t _Size,
                                size_t _Alignment
    );






















__pragma(pack(pop))

#pragma warning(pop) 












#pragma once










#pragma once





#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )


__pragma(pack(push, 8))
















     int* __cdecl _errno(void);
    

     errno_t __cdecl _set_errno(  int _Value);
     errno_t __cdecl _get_errno(  int* _Value);






    


        
    




 extern unsigned long  __cdecl __threadid(void);

 extern uintptr_t __cdecl __threadhandle(void);



__pragma(pack(pop))

#pragma warning(pop) 



#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )


__pragma(pack(push, 8))


    typedef int (__cdecl* _CoreCrtSecureSearchSortCompareFunction)(void*, void const*, void const*);
    typedef int (__cdecl* _CoreCrtNonSecureSearchSortCompareFunction)(void const*, void const*);




     
     void* __cdecl bsearch_s(
                                                        void const* _Key,
          void const* _Base,
                                                        rsize_t     _NumOfElements,
                                                        rsize_t     _SizeOfElements,
                            _CoreCrtSecureSearchSortCompareFunction _CompareFunction,
                                                    void*       _Context
        );

     void __cdecl qsort_s(
          void*   _Base,
                                                             rsize_t _NumOfElements,
                                                             rsize_t _SizeOfElements,
                             _CoreCrtSecureSearchSortCompareFunction _CompareFunction,
                                                         void*   _Context
        );





 
 void* __cdecl bsearch(
                                                    void const* _Key,
      void const* _Base,
                                                    size_t      _NumOfElements,
                                                    size_t      _SizeOfElements,
                     _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
    );

 void __cdecl qsort(
      void*  _Base,
                                                         size_t _NumOfElements,
                                                         size_t _SizeOfElements,
                     _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
    );

 
 void* __cdecl _lfind_s(
                                                       void const*   _Key,
      void const*   _Base,
                                                    unsigned int* _NumOfElements,
                                                       size_t        _SizeOfElements,
                             _CoreCrtSecureSearchSortCompareFunction _CompareFunction,
                                                       void*         _Context
    );

 
 void* __cdecl _lfind(
                                                       void const*   _Key,
      void const*   _Base,
                                                    unsigned int* _NumOfElements,
                                                       unsigned int  _SizeOfElements,
                          _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
    );

 
 void* __cdecl _lsearch_s(
                                                             void const*   _Key,
      void*         _Base,
                                                          unsigned int* _NumOfElements,
                                                             size_t        _SizeOfElements,
                                   _CoreCrtSecureSearchSortCompareFunction _CompareFunction,
                                                             void*         _Context
    );

 
 void* __cdecl _lsearch(
                                                             void const*   _Key,
      void*         _Base,
                                                          unsigned int* _NumOfElements,
                                                             unsigned int  _SizeOfElements,
                                _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
    );


























































































      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_lfind" ". See online help for details."))
     void* __cdecl lfind(
                                                           void const*   _Key,
          void const*   _Base,
                                                        unsigned int* _NumOfElements,
                                                           unsigned int  _SizeOfElements,
                              _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
        );

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_lsearch" ". See online help for details."))
     void* __cdecl lsearch(
                                                                void const*   _Key,
          void*         _Base,
                                                             unsigned int* _NumOfElements,
                                                                unsigned int  _SizeOfElements,
                                   _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
        );





__pragma(pack(pop))

#pragma warning(pop) 










#pragma once



#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )


__pragma(pack(push, 8))


































     
    
     errno_t __cdecl _itow_s(
                                  int      _Value,
          wchar_t* _Buffer,
                                  size_t   _BufferCount,
                                  int      _Radix
        );

    

      wchar_t* __cdecl _itow( int _Value,   wchar_t *_Buffer,  int _Radix);

     
    
     errno_t __cdecl _ltow_s(
                                  long     _Value,
          wchar_t* _Buffer,
                                  size_t   _BufferCount,
                                  int      _Radix
        );

    

      wchar_t* __cdecl _ltow( long _Value,   wchar_t *_Buffer,  int _Radix);

    
     errno_t __cdecl _ultow_s(
                                  unsigned long _Value,
          wchar_t*      _Buffer,
                                  size_t        _BufferCount,
                                  int           _Radix
        );

    

      wchar_t* __cdecl _ultow( unsigned long _Value,   wchar_t *_Buffer,  int _Radix);

     
     double __cdecl wcstod(
                            wchar_t const* _String,
            wchar_t**      _EndPtr
        );

     
     double __cdecl _wcstod_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                          _locale_t      _Locale
        );

     
     long __cdecl wcstol(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix
        );

     
     long __cdecl _wcstol_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix,
                          _locale_t      _Locale
        );

     
     long long __cdecl wcstoll(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix
        );

     
     long long __cdecl _wcstoll_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix,
                          _locale_t      _Locale
        );

     
     unsigned long __cdecl wcstoul(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix
        );

     
     unsigned long __cdecl _wcstoul_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix,
                          _locale_t      _Locale
        );

     
     unsigned long long __cdecl wcstoull(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix
        );

     
     unsigned long long __cdecl _wcstoull_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix,
                          _locale_t      _Locale
        );

     
     long double __cdecl wcstold(
                            wchar_t const* _String,
            wchar_t**      _EndPtr
        );

     
     long double __cdecl _wcstold_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                          _locale_t      _Locale
        );

     
     float __cdecl wcstof(
                            wchar_t const* _String,
            wchar_t**      _EndPtr
        );

     
     float __cdecl _wcstof_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                          _locale_t      _Locale
        );

     
     double __cdecl _wtof(
          wchar_t const* _String
        );

     
     double __cdecl _wtof_l(
            wchar_t const* _String,
          _locale_t      _Locale
        );

     
     int __cdecl _wtoi(
          wchar_t const* _String
        );

     
     int __cdecl _wtoi_l(
            wchar_t const* _String,
          _locale_t      _Locale
        );

     
     long __cdecl _wtol(
          wchar_t const* _String
        );

     
     long __cdecl _wtol_l(
            wchar_t const* _String,
          _locale_t      _Locale
        );

     
     long long __cdecl _wtoll(
          wchar_t const* _String
        );

     
     long long __cdecl _wtoll_l(
            wchar_t const* _String,
          _locale_t      _Locale
        );

    
     errno_t __cdecl _i64tow_s(
                                  __int64  _Value,
          wchar_t* _Buffer,
                                  size_t   _BufferCount,
                                  int      _Radix
        );

    
     wchar_t* __cdecl _i64tow(
                            __int64  _Value,
            wchar_t* _Buffer,
                            int      _Radix
        );

    
     errno_t __cdecl _ui64tow_s(
                                  unsigned __int64 _Value,
          wchar_t*         _Buffer,
                                  size_t           _BufferCount,
                                  int              _Radix
        );

    
     wchar_t* __cdecl _ui64tow(
                            unsigned __int64 _Value,
            wchar_t*         _Buffer,
                            int              _Radix
        );

     
     __int64 __cdecl _wtoi64(
          wchar_t const* _String
        );

     
     __int64 __cdecl _wtoi64_l(
            wchar_t const* _String,
          _locale_t      _Locale
        );

     
     __int64 __cdecl _wcstoi64(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix
        );

     
     __int64 __cdecl _wcstoi64_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix,
                          _locale_t      _Locale
        );

     
     unsigned __int64 __cdecl _wcstoui64(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix
        );

     
     unsigned __int64 __cdecl _wcstoui64_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix,
                          _locale_t      _Locale
        );

    
    

     
     
     __declspec(allocator) wchar_t* __cdecl _wfullpath(
          wchar_t*       _Buffer,
                                    wchar_t const* _Path,
                                      size_t         _BufferCount
        );

    

    
     errno_t __cdecl _wmakepath_s(
          wchar_t*       _Buffer,
                                  size_t         _BufferCount,
                            wchar_t const* _Drive,
                            wchar_t const* _Dir,
                            wchar_t const* _Filename,
                            wchar_t const* _Ext
        );

    

  void __cdecl _wmakepath(  wchar_t *_Buffer,  wchar_t const* _Drive,  wchar_t const* _Dir,  wchar_t const* _Filename,  wchar_t const* _Ext);

     void __cdecl _wperror(
          wchar_t const* _ErrorMessage
        );

    
     void __cdecl _wsplitpath(
                            wchar_t const* _FullPath,
            wchar_t*       _Drive,
            wchar_t*       _Dir,
            wchar_t*       _Filename,
            wchar_t*       _Ext
        );

     errno_t __cdecl _wsplitpath_s(
                                      wchar_t const* _FullPath,
             wchar_t*       _Drive,
                                        size_t         _DriveCount,
               wchar_t*       _Dir,
                                        size_t         _DirCount,
          wchar_t*       _Filename,
                                        size_t         _FilenameCount,
               wchar_t*       _Ext,
                                        size_t         _ExtCount
        );

    

        
        

        
         errno_t __cdecl _wdupenv_s(
                wchar_t**      _Buffer,
                                                                                size_t*        _BufferCount,
                                                                                   wchar_t const* _VarName
            );

        

          
         wchar_t* __cdecl _wgetenv(
              wchar_t const* _VarName
            );

         
        
         errno_t __cdecl _wgetenv_s(
                                         size_t*        _RequiredCount,
              wchar_t*       _Buffer,
                                          size_t         _BufferCount,
                                        wchar_t const* _VarName
            );

        

         
         int __cdecl _wputenv(
              wchar_t const* _EnvString
            );

        
         errno_t __cdecl _wputenv_s(
              wchar_t const* _Name,
              wchar_t const* _Value
            );

         errno_t __cdecl _wsearchenv_s(
                                    wchar_t const* _Filename,
                                    wchar_t const* _VarName,
              wchar_t*       _Buffer,
                                      size_t         _BufferCount
            );

        

          void __cdecl _wsearchenv( wchar_t const* _Filename,  wchar_t const* _VarName,   wchar_t *_ResultPath);

         int __cdecl _wsystem(
              wchar_t const* _Command
            );





__pragma(pack(pop))

#pragma warning(pop) 









#pragma once




#pragma warning(push)
#pragma warning(disable:   4514 4820 )

__pragma(pack(push, 8))







    
    




































    
    
        
    





    


__pragma(pack(pop))

#pragma warning(pop) 


#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )


__pragma(pack(push, 8))




    










 void __cdecl _swab(
        char* _Buf1,
        char* _Buf2,
                                                                  int   _SizeInBytes
    );













     __declspec(noreturn) void __cdecl exit(  int _Code);
     __declspec(noreturn) void __cdecl _exit(  int _Code);
     __declspec(noreturn) void __cdecl _Exit(  int _Code);
     __declspec(noreturn) void __cdecl quick_exit(  int _Code);
     __declspec(noreturn) void __cdecl abort(void);






 unsigned int __cdecl _set_abort_behavior(
      unsigned int _Flags,
      unsigned int _Mask
    );




    

    typedef int (__cdecl* _onexit_t)(void);
    





    
    


























































    int       __cdecl atexit(void (__cdecl*)(void));
    _onexit_t __cdecl _onexit(  _onexit_t _Func);


int __cdecl at_quick_exit(void (__cdecl*)(void));









    
    typedef void (__cdecl* _purecall_handler)(void);

    
    typedef void (__cdecl* _invalid_parameter_handler)(
        wchar_t const*,
        wchar_t const*,
        wchar_t const*,
        unsigned int,
        uintptr_t
        );

    
     _purecall_handler __cdecl _set_purecall_handler(
          _purecall_handler _Handler
        );

     _purecall_handler __cdecl _get_purecall_handler(void);

    
     _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(
          _invalid_parameter_handler _Handler
        );

     _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(void);

     _invalid_parameter_handler __cdecl _set_thread_local_invalid_parameter_handler(
          _invalid_parameter_handler _Handler
        );

     _invalid_parameter_handler __cdecl _get_thread_local_invalid_parameter_handler(void);























  int __cdecl _set_error_mode(  int _Mode);




     int* __cdecl _errno(void);
    

     errno_t __cdecl _set_errno(  int _Value);
     errno_t __cdecl _get_errno(  int* _Value);

     unsigned long* __cdecl __doserrno(void);
    

     errno_t __cdecl _set_doserrno(  unsigned long _Value);
     errno_t __cdecl _get_doserrno(  unsigned long * _Value);

    
      char** __cdecl __sys_errlist(void);
    

      int * __cdecl __sys_nerr(void);
    

     void __cdecl perror(  char const* _ErrMsg);





  char**    __cdecl __p__pgmptr (void);
  wchar_t** __cdecl __p__wpgmptr(void);
  int*      __cdecl __p__fmode  (void);








    
    
    


 
 errno_t __cdecl _get_pgmptr (  char**    _Value);

 
 errno_t __cdecl _get_wpgmptr(  wchar_t** _Value);

 errno_t __cdecl _set_fmode  (               int       _Mode );

 errno_t __cdecl _get_fmode  (              int*      _PMode);








typedef struct _div_t
{
    int quot;
    int rem;
} div_t;

typedef struct _ldiv_t
{
    long quot;
    long rem;
} ldiv_t;

typedef struct _lldiv_t
{
    long long quot;
    long long rem;
} lldiv_t;

  int       __cdecl abs   (  int       _Number);
  long      __cdecl labs  (  long      _Number);
  long long __cdecl llabs (  long long _Number);
  __int64   __cdecl _abs64(  __int64   _Number);

  unsigned short   __cdecl _byteswap_ushort(  unsigned short   _Number);
  unsigned long    __cdecl _byteswap_ulong (  unsigned long    _Number);
  unsigned __int64 __cdecl _byteswap_uint64(  unsigned __int64 _Number);

   div_t   __cdecl div  (  int       _Numerator,   int       _Denominator);
   ldiv_t  __cdecl ldiv (  long      _Numerator,   long      _Denominator);
   lldiv_t __cdecl lldiv(  long long _Numerator,   long long _Denominator);



#pragma warning(push)
#pragma warning(disable: 6540)

unsigned int __cdecl _rotl(
      unsigned int _Value,
      int          _Shift
    );

 
unsigned long __cdecl _lrotl(
      unsigned long _Value,
      int           _Shift
    );

unsigned __int64 __cdecl _rotl64(
      unsigned __int64 _Value,
      int              _Shift
    );

unsigned int __cdecl _rotr(
      unsigned int _Value,
      int          _Shift
    );

 
unsigned long __cdecl _lrotr(
      unsigned long _Value,
      int           _Shift
    );

unsigned __int64 __cdecl _rotr64(
      unsigned __int64 _Value,
      int              _Shift
    );

#pragma warning(pop)






 void __cdecl srand(  unsigned int _Seed);

   int __cdecl rand(void);









































    #pragma pack(push, 4)
    typedef struct
    {
        unsigned char ld[10];
    } _LDOUBLE;
    #pragma pack(pop)

    













typedef struct
{
    double x;
} _CRT_DOUBLE;

typedef struct
{
    float f;
} _CRT_FLOAT;





typedef struct
{
    long double x;
} _LONGDOUBLE;



#pragma pack(push, 4)
typedef struct
{
    unsigned char ld12[12];
} _LDBL12;
#pragma pack(pop)








                      double    __cdecl atof   (  char const* _String);
    int       __cdecl atoi   (  char const* _String);
                      long      __cdecl atol   (  char const* _String);
                      long long __cdecl atoll  (  char const* _String);
                      __int64   __cdecl _atoi64(  char const* _String);

   double    __cdecl _atof_l  (  char const* _String,   _locale_t _Locale);
   int       __cdecl _atoi_l  (  char const* _String,   _locale_t _Locale);
   long      __cdecl _atol_l  (  char const* _String,   _locale_t _Locale);
   long long __cdecl _atoll_l (  char const* _String,   _locale_t _Locale);
   __int64   __cdecl _atoi64_l(  char const* _String,   _locale_t _Locale);

   int __cdecl _atoflt (  _CRT_FLOAT*  _Result,   char const* _String);
   int __cdecl _atodbl (  _CRT_DOUBLE* _Result,   char*       _String);
   int __cdecl _atoldbl(  _LDOUBLE*    _Result,   char*       _String);

 
 int __cdecl _atoflt_l(
         _CRT_FLOAT* _Result,
        char const* _String,
      _locale_t   _Locale
    );

 
 int __cdecl _atodbl_l(
         _CRT_DOUBLE* _Result,
        char*        _String,
      _locale_t    _Locale
    );


 
 int __cdecl _atoldbl_l(
         _LDOUBLE* _Result,
        char*     _String,
      _locale_t _Locale
    );

 
 float __cdecl strtof(
                        char const* _String,
        char**      _EndPtr
    );

 
 float __cdecl _strtof_l(
                        char const* _String,
        char**      _EndPtr,
                      _locale_t   _Locale
    );

 
 double __cdecl strtod(
                        char const* _String,
        char**      _EndPtr
    );

 
 double __cdecl _strtod_l(
                        char const* _String,
        char**      _EndPtr,
                      _locale_t   _Locale
    );

 
 long double __cdecl strtold(
                        char const* _String,
        char**      _EndPtr
    );

 
 long double __cdecl _strtold_l(
                        char const* _String,
        char**      _EndPtr,
                      _locale_t   _Locale
    );

 
 long __cdecl strtol(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix
    );

 
 long __cdecl _strtol_l(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix,
                      _locale_t   _Locale
    );

 
 long long __cdecl strtoll(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix
    );

 
 long long __cdecl _strtoll_l(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix,
                      _locale_t   _Locale
    );

 
 unsigned long __cdecl strtoul(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix
    );

 
 unsigned long __cdecl _strtoul_l(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix,
                      _locale_t   _Locale
    );

 
 unsigned long long __cdecl strtoull(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix
    );

 
 unsigned long long __cdecl _strtoull_l(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix,
                      _locale_t   _Locale
    );

 
 __int64 __cdecl _strtoi64(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix
    );

 
 __int64 __cdecl _strtoi64_l(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix,
                      _locale_t   _Locale
    );

 
 unsigned __int64 __cdecl _strtoui64(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix
    );

 
 unsigned __int64 __cdecl _strtoui64_l(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix,
                      _locale_t   _Locale
    );








 

 errno_t __cdecl _itoa_s(
                              int    _Value,
      char*  _Buffer,
                              size_t _BufferCount,
                              int    _Radix
    );



  char* __cdecl _itoa( int _Value,   char *_Buffer,  int _Radix);

 

 errno_t __cdecl _ltoa_s(
                              long   _Value,
      char*  _Buffer,
                              size_t _BufferCount,
                              int    _Radix
    );



  char* __cdecl _ltoa( long _Value,   char *_Buffer,  int _Radix);

 

 errno_t __cdecl _ultoa_s(
                              unsigned long _Value,
      char*         _Buffer,
                              size_t        _BufferCount,
                              int           _Radix
    );



  char* __cdecl _ultoa( unsigned long _Value,   char *_Buffer,  int _Radix);

 

 errno_t __cdecl _i64toa_s(
                              __int64 _Value,
      char*   _Buffer,
                              size_t  _BufferCount,
                              int     _Radix
    );

 

 char* __cdecl _i64toa(
                        __int64 _Value,
        char*   _Buffer,
                        int     _Radix
    );

 

 errno_t __cdecl _ui64toa_s(
                              unsigned __int64 _Value,
      char*            _Buffer,
                              size_t           _BufferCount,
                              int              _Radix
    );


 char* __cdecl _ui64toa(
                        unsigned __int64 _Value,
        char*            _Buffer,
                        int              _Radix
    );













 

 errno_t __cdecl _ecvt_s(
      char* _Buffer,
       size_t                       _BufferCount,
       double                       _Value,
       int                          _DigitCount,
      int*                         _PtDec,
      int*                         _PtSign
    );



  
 char* __cdecl _ecvt(
       double _Value,
       int    _DigitCount,
      int*   _PtDec,
      int*   _PtSign
    );

 

 errno_t __cdecl _fcvt_s(
      char*  _Buffer,
                              size_t _BufferCount,
                              double _Value,
                              int    _FractionalDigitCount,
                             int*   _PtDec,
                             int*   _PtSign
    );



 
  
 char* __cdecl _fcvt(
       double _Value,
       int    _FractionalDigitCount,
      int*   _PtDec,
      int*   _PtSign
    );

 
 errno_t __cdecl _gcvt_s(
      char*  _Buffer,
                              size_t _BufferCount,
                              double _Value,
                              int    _DigitCount
    );




 char* __cdecl _gcvt(
                        double _Value,
                        int    _DigitCount,
        char*  _Buffer
    );











    


        
    

    


        
    

     
     int __cdecl ___mb_cur_max_func(void);

     
     int __cdecl ___mb_cur_max_l_func(_locale_t _Locale);




 
 int __cdecl mblen(
        char const* _Ch,
                                             size_t      _MaxCount
    );

 
 int __cdecl _mblen_l(
        char const* _Ch,
                                             size_t      _MaxCount,
                                         _locale_t   _Locale
    );

 
 
 size_t __cdecl _mbstrlen(
      char const* _String
    );

 
 
 size_t __cdecl _mbstrlen_l(
        char const* _String,
      _locale_t   _Locale
    );

 
 
 size_t __cdecl _mbstrnlen(
      char const* _String,
        size_t      _MaxCount
    );

 
 
 size_t __cdecl _mbstrnlen_l(
        char const* _String,
          size_t      _MaxCount,
      _locale_t   _Locale
    );

 
 int __cdecl mbtowc(
                      wchar_t*    _DstCh,
      char const* _SrcCh,
                                      size_t      _SrcSizeInBytes
    );

 
 int __cdecl _mbtowc_l(
                      wchar_t*    _DstCh,
      char const* _SrcCh,
                                      size_t      _SrcSizeInBytes,
                                  _locale_t   _Locale
    );


 errno_t __cdecl mbstowcs_s(
                                                      size_t*     _PtNumOfCharConverted,
      wchar_t*    _DstBuf,
                                                           size_t      _SizeInWords,
                                     char const* _SrcBuf,
                                                           size_t      _MaxCount
    );



  size_t __cdecl mbstowcs( wchar_t *_Dest,  char const* _Source,  size_t _MaxCount);


 errno_t __cdecl _mbstowcs_s_l(
                                                      size_t*     _PtNumOfCharConverted,
      wchar_t*    _DstBuf,
                                                           size_t      _SizeInWords,
                                     char const* _SrcBuf,
                                                           size_t      _MaxCount,
                                                       _locale_t   _Locale
    );



  size_t __cdecl _mbstowcs_l(  wchar_t *_Dest,   char const* _Source,   size_t _MaxCount,   _locale_t _Locale);





 int __cdecl wctomb(
      char*   _MbCh,
                                wchar_t _WCh
    );


 int __cdecl _wctomb_l(
        char*     _MbCh,
                          wchar_t   _WCh,
                      _locale_t _Locale
    );



    
     errno_t __cdecl wctomb_s(
                                                         int*    _SizeConverted,
          char*   _MbCh,
                                                              rsize_t _SizeInBytes,
                                                              wchar_t _WCh
        );




 errno_t __cdecl _wctomb_s_l(
                             int*     _SizeConverted,
      char*     _MbCh,
                                  size_t    _SizeInBytes,
                                  wchar_t   _WCh,
                              _locale_t _Locale);


 errno_t __cdecl wcstombs_s(
                                                               size_t*        _PtNumOfCharConverted,
      char*          _Dst,
                                                                    size_t         _DstSizeInBytes,
                                                                  wchar_t const* _Src,
                                                                    size_t         _MaxCountInBytes
    );



  size_t __cdecl wcstombs( char *_Dest,  wchar_t const* _Source,  size_t _MaxCount);


 errno_t __cdecl _wcstombs_s_l(
                                                               size_t*        _PtNumOfCharConverted,
      char*          _Dst,
                                                                    size_t         _DstSizeInBytes,
                                                                  wchar_t const* _Src,
                                                                    size_t         _MaxCountInBytes,
                                                                _locale_t      _Locale
    );



  size_t __cdecl _wcstombs_l(  char *_Dest,   wchar_t const* _Source,   size_t _MaxCount,   _locale_t _Locale);




















 
 
 __declspec(allocator) char* __cdecl _fullpath(
      char*       _Buffer,
                                char const* _Path,
                                  size_t      _BufferCount
    );




 errno_t __cdecl _makepath_s(
      char*       _Buffer,
                              size_t      _BufferCount,
                        char const* _Drive,
                        char const* _Dir,
                        char const* _Filename,
                        char const* _Ext
    );



  void __cdecl _makepath(  char *_Buffer,  char const* _Drive,  char const* _Dir,  char const* _Filename,  char const* _Ext);


 void __cdecl _splitpath(
                        char const* _FullPath,
        char*       _Drive,
        char*       _Dir,
        char*       _Filename,
        char*       _Ext
    );


 errno_t __cdecl _splitpath_s(
                                  char const* _FullPath,
         char*       _Drive,
                                    size_t      _DriveCount,
           char*       _Dir,
                                    size_t      _DirCount,
      char*       _Filename,
                                    size_t      _FilenameCount,
           char*       _Ext,
                                    size_t      _ExtCount
    );






 
 errno_t __cdecl getenv_s(
                                 size_t*     _RequiredCount,
      char*       _Buffer,
                                  rsize_t     _BufferCount,
                                char const* _VarName
    );






 int*       __cdecl __p___argc (void);
 char***    __cdecl __p___argv (void);
 wchar_t*** __cdecl __p___wargv(void);






    
    
    


 char***    __cdecl __p__environ (void);
 wchar_t*** __cdecl __p__wenviron(void);


    








    
    










      
     char* __cdecl getenv(
          char const* _VarName
        );

    

    




    
     errno_t __cdecl _dupenv_s(
            char**      _Buffer,
                                                                            size_t*     _BufferCount,
                                                                               char const* _VarName
        );

    



     int __cdecl system(
          char const* _Command
        );

    
    
    #pragma warning(push)
    #pragma warning(disable: 6540)

     
     int __cdecl _putenv(
          char const* _EnvString
        );

    
     errno_t __cdecl _putenv_s(
          char const* _Name,
          char const* _Value
        );

    #pragma warning(pop)

     errno_t __cdecl _searchenv_s(
                                char const* _Filename,
                                char const* _VarName,
          char*       _Buffer,
                                  size_t      _BufferCount
        );

    

      void __cdecl _searchenv( char const* _Filename,  char const* _VarName,   char *_Buffer);

    
    __declspec(deprecated("This function or variable has been superceded by newer library " "or operating system functionality. Consider using " "SetErrorMode" " " "instead. See online help for details."))
     void __cdecl _seterrormode(
          int _Mode
        );

    __declspec(deprecated("This function or variable has been superceded by newer library " "or operating system functionality. Consider using " "Beep" " " "instead. See online help for details."))
     void __cdecl _beep(
          unsigned _Frequency,
          unsigned _Duration
        );

    __declspec(deprecated("This function or variable has been superceded by newer library " "or operating system functionality. Consider using " "Sleep" " " "instead. See online help for details."))
     void __cdecl _sleep(
          unsigned long _Duration
        );











    
        
        
    

    
    

    #pragma warning(push)
    #pragma warning(disable: 4141) 

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_ecvt" ". See online help for details.")) 
     char* __cdecl ecvt(
           double _Value,
           int    _DigitCount,
          int*   _PtDec,
          int*   _PtSign
        );

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_fcvt" ". See online help for details.")) 
     char* __cdecl fcvt(
           double _Value,
           int    _FractionalDigitCount,
          int*   _PtDec,
          int*   _PtSign
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_gcvt" ". See online help for details.")) 
     char* __cdecl gcvt(
                            double _Value,
                            int    _DigitCount,
            char*  _DstBuf
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_itoa" ". See online help for details.")) 
     char* __cdecl itoa(
                            int   _Value,
            char* _Buffer,
                            int   _Radix
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_ltoa" ". See online help for details.")) 
     char* __cdecl ltoa(
                            long  _Value,
            char* _Buffer,
                            int   _Radix
        );


    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_swab" ". See online help for details."))
     void __cdecl swab(
          char* _Buf1,
          char* _Buf2,
                                     int   _SizeInBytes
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_ultoa" ". See online help for details.")) 
     char* __cdecl ultoa(
                            unsigned long _Value,
            char*         _Buffer,
                            int           _Radix
        );

    

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_putenv" ". See online help for details."))
     int __cdecl putenv(
          char const* _EnvString
        );

    #pragma warning(pop)

    _onexit_t __cdecl onexit(  _onexit_t _Func);





__pragma(pack(pop))

#pragma warning(pop) 










#pragma once















#pragma once










#pragma once










#pragma once





#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )


__pragma(pack(push, 8))




     int* __cdecl _errno(void);
    

     errno_t __cdecl _set_errno(  int _Value);
     errno_t __cdecl _get_errno(  int* _Value);

     unsigned long* __cdecl __doserrno(void);
    

     errno_t __cdecl _set_doserrno(  unsigned long _Value);
     errno_t __cdecl _get_doserrno(  unsigned long * _Value);











































    
    
    
    
    







    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    




__pragma(pack(pop))

#pragma warning(pop) 










#pragma once



#pragma warning(push)
#pragma warning(disable:   4514 4820 )



__pragma(pack(push, 8))



  
 void * __cdecl memchr(
      void const* _Buf,
                                 int         _Val,
                                 size_t      _MaxCount
    );

  
int __cdecl memcmp(
      void const* _Buf1,
      void const* _Buf2,
                         size_t      _Size
    );


 

void* __cdecl memcpy(
      void* _Dst,
            void const* _Src,
                               size_t      _Size
    );


 void* __cdecl memmove(
      void*       _Dst,
            void const* _Src,
                                   size_t      _Size
    );

 

void* __cdecl memset(
      void*  _Dst,
                               int    _Val,
                               size_t _Size
    );

  
 char * __cdecl strchr(
      char const* _Str,
        int         _Val
    );

  
 char * __cdecl strrchr(
      char const* _Str,
        int         _Ch
    );

    
 char * __cdecl strstr(
      char const* _Str,
      char const* _SubStr
    );

  

 wchar_t * __cdecl wcschr(
      wchar_t const* _Str,
        wchar_t        _Ch
    );

  
 wchar_t * __cdecl wcsrchr(
      wchar_t const* _Str,
        wchar_t        _Ch
    );

    

 wchar_t * __cdecl wcsstr(
      wchar_t const* _Str,
      wchar_t const* _SubStr
    );



__pragma(pack(pop))



#pragma warning(pop) 


#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )


__pragma(pack(push, 8))


    















     
    
    static __inline errno_t __cdecl memcpy_s(
          void*       const _Destination,
                                                              rsize_t     const _DestinationSize,
                                 void const* const _Source,
                                                              rsize_t     const _SourceSize
        )
    {
        if (_SourceSize == 0)
        {
            return 0;
        }

        { int _Expr_val=!!(_Destination != ((void *)0)); if (!(_Expr_val)) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; } };
        if (_Source == ((void *)0) || _DestinationSize < _SourceSize)
        {
            memset(_Destination, 0, _DestinationSize);

            { int _Expr_val=!!(_Source != ((void *)0)); if (!(_Expr_val)) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; } };
            { int _Expr_val=!!(_DestinationSize >= _SourceSize); if (!(_Expr_val)) { (*_errno()) = 34; _invalid_parameter_noinfo(); return 34; } };

            
            return 22;
        }
        memcpy(_Destination, _Source, _SourceSize);
        return 0;
    }

    
    static __inline errno_t __cdecl memmove_s(
          void*       const _Destination,
                                                              rsize_t     const _DestinationSize,
                                 void const* const _Source,
                                                              rsize_t     const _SourceSize
        )
    {
        if (_SourceSize == 0)
        {
            return 0;
        }

        { int _Expr_val=!!(_Destination != ((void *)0)); if (!(_Expr_val)) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; } };
        { int _Expr_val=!!(_Source != ((void *)0)); if (!(_Expr_val)) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; } };
        { int _Expr_val=!!(_DestinationSize >= _SourceSize); if (!(_Expr_val)) { (*_errno()) = 34; _invalid_parameter_noinfo(); return 34; } };

        memmove(_Destination, _Source, _SourceSize);
        return 0;
    }






#pragma warning(pop) 
__pragma(pack(pop))



#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )




__pragma(pack(push, 8))



 
 int __cdecl _memicmp(
      void const* _Buf1,
      void const* _Buf2,
                             size_t      _Size
    );

 
 int __cdecl _memicmp_l(
      void const* _Buf1,
      void const* _Buf2,
                             size_t      _Size,
                         _locale_t   _Locale
    );





    














    




















    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_memccpy" ". See online help for details."))
     void* __cdecl memccpy(
          void*       _Dst,
            void const* _Src,
                                   int         _Val,
                                   size_t      _Size
        );

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_memicmp" ". See online help for details."))
     int __cdecl memicmp(
          void const* _Buf1,
          void const* _Buf2,
                                 size_t      _Size
        );






















__pragma(pack(pop))



#pragma warning(pop) 










#pragma once




#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )




__pragma(pack(push, 8))










    
     errno_t __cdecl wcscat_s(
          wchar_t* _Destination,
          rsize_t _SizeInWords,
          wchar_t const* _Source
        );

    
     errno_t __cdecl wcscpy_s(
          wchar_t* _Destination,
          rsize_t _SizeInWords,
          wchar_t const* _Source
        );

    
     errno_t __cdecl wcsncat_s(
          wchar_t*       _Destination,
                                     rsize_t        _SizeInWords,
               wchar_t const* _Source,
                                     rsize_t        _MaxCount
        );

    
     errno_t __cdecl wcsncpy_s(
          wchar_t*       _Destination,
                                  rsize_t        _SizeInWords,
            wchar_t const* _Source,
                                  rsize_t        _MaxCount
        );

     
     wchar_t* __cdecl wcstok_s(
                          wchar_t*       _String,
                                 wchar_t const* _Delimiter,
            wchar_t**      _Context
        );















 
 __declspec(allocator) wchar_t* __cdecl _wcsdup(
      wchar_t const* _String
    );










      wchar_t* __cdecl wcscat( wchar_t *_Destination,  wchar_t const* _Source);


 
 int __cdecl wcscmp(
      wchar_t const* _String1,
      wchar_t const* _String2
    );



  wchar_t* __cdecl wcscpy( wchar_t *_Destination,  wchar_t const* _Source);

 
 size_t __cdecl wcscspn(
      wchar_t const* _String,
      wchar_t const* _Control
    );

 
 size_t __cdecl wcslen(
      wchar_t const* _String
    );

 


 size_t __cdecl wcsnlen(
      wchar_t const* _Source,
                            size_t         _MaxCount
    );



     
    
    
    static __inline size_t __cdecl wcsnlen_s(
          wchar_t const* _Source,
                                size_t         _MaxCount
        )
    {
        return (_Source == 0) ? 0 : wcsnlen(_Source, _MaxCount);
    }





  wchar_t* __cdecl wcsncat(  wchar_t *_Destination,   wchar_t const* _Source,   size_t _Count);

 
 int __cdecl wcsncmp(
      wchar_t const* _String1,
      wchar_t const* _String2,
                            size_t         _MaxCount
    );



  wchar_t* __cdecl wcsncpy(    wchar_t *_Destination,   wchar_t const* _Source,   size_t _Count);

 
 wchar_t * __cdecl wcspbrk(
      wchar_t const* _String,
      wchar_t const* _Control
    );

 
 size_t __cdecl wcsspn(
      wchar_t const* _String,
      wchar_t const* _Control
    );

  
 wchar_t* __cdecl wcstok(
                          wchar_t*       _String,
                                 wchar_t const* _Delimiter,
        wchar_t**      _Context
    );



    


        



    

      
    static __inline wchar_t* __cdecl _wcstok(
          wchar_t*       const _String,
                 wchar_t const* const _Delimiter
        )
    {
        return wcstok(_String, _Delimiter, 0);
    }

    



    














 
  
 wchar_t* __cdecl _wcserror(
      int _ErrorNumber
    );


 errno_t __cdecl _wcserror_s(
      wchar_t* _Buffer,
                                  size_t   _SizeInWords,
                                  int      _ErrorNumber
    );



 
 
  
 wchar_t* __cdecl __wcserror(
      wchar_t const* _String
    );

  errno_t __cdecl __wcserror_s(
      wchar_t*       _Buffer,
                                  size_t         _SizeInWords,
                                wchar_t const* _ErrorMessage
    );



   int __cdecl _wcsicmp(
      wchar_t const* _String1,
      wchar_t const* _String2
    );

   int __cdecl _wcsicmp_l(
        wchar_t const* _String1,
        wchar_t const* _String2,
      _locale_t      _Locale
    );

   int __cdecl _wcsnicmp(
      wchar_t const* _String1,
      wchar_t const* _String2,
                            size_t         _MaxCount
    );

   int __cdecl _wcsnicmp_l(
      wchar_t const* _String1,
      wchar_t const* _String2,
                            size_t         _MaxCount,
                        _locale_t      _Locale
    );

  errno_t __cdecl _wcsnset_s(
      wchar_t* _Destination,
                                 size_t   _SizeInWords,
                                 wchar_t  _Value,
                                 size_t   _MaxCount
    );



  wchar_t* __cdecl _wcsnset(  wchar_t *_String,   wchar_t _Value,   size_t _MaxCount);

 wchar_t* __cdecl _wcsrev(
      wchar_t* _String
    );

  errno_t __cdecl _wcsset_s(
      wchar_t* _Destination,
                                 size_t   _SizeInWords,
                                 wchar_t  _Value
    );



  wchar_t* __cdecl _wcsset(  wchar_t *_String,   wchar_t _Value);

  errno_t __cdecl _wcslwr_s(
      wchar_t* _String,
                                 size_t   _SizeInWords
    );



  wchar_t* __cdecl _wcslwr( wchar_t *_String);


 errno_t __cdecl _wcslwr_s_l(
      wchar_t*  _String,
                                 size_t    _SizeInWords,
                             _locale_t _Locale
    );



  wchar_t* __cdecl _wcslwr_l(  wchar_t *_String,   _locale_t _Locale);


 errno_t __cdecl _wcsupr_s(
      wchar_t* _String,
                          size_t   _Size
    );



  wchar_t* __cdecl _wcsupr( wchar_t *_String);


 errno_t __cdecl _wcsupr_s_l(
      wchar_t*  _String,
                          size_t    _Size,
                      _locale_t _Locale
    );



  wchar_t* __cdecl _wcsupr_l(  wchar_t *_String,   _locale_t _Locale);

 

 size_t __cdecl wcsxfrm(
        wchar_t*       _Destination,
                                         wchar_t const* _Source,
                size_t         _MaxCount
    );

 

 size_t __cdecl _wcsxfrm_l(
        wchar_t*       _Destination,
                                         wchar_t const* _Source,
                size_t         _MaxCount,
                                       _locale_t      _Locale
    );

 
 int __cdecl wcscoll(
      wchar_t const* _String1,
      wchar_t const* _String2
    );

 
 int __cdecl _wcscoll_l(
        wchar_t const* _String1,
        wchar_t const* _String2,
      _locale_t      _Locale
    );

 
 int __cdecl _wcsicoll(
      wchar_t const* _String1,
      wchar_t const* _String2
    );

 
 int __cdecl _wcsicoll_l(
        wchar_t const* _String1,
        wchar_t const* _String2,
      _locale_t      _Locale
    );

 
 int __cdecl _wcsncoll(
      wchar_t const* _String1,
      wchar_t const* _String2,
                            size_t         _MaxCount
    );

 
 int __cdecl _wcsncoll_l(
      wchar_t const* _String1,
      wchar_t const* _String2,
                            size_t         _MaxCount,
                        _locale_t      _Locale
    );

 
 int __cdecl _wcsnicoll(
      wchar_t const* _String1,
      wchar_t const* _String2,
                            size_t         _MaxCount
    );

 
 int __cdecl _wcsnicoll_l(
      wchar_t const* _String1,
      wchar_t const* _String2,
                            size_t         _MaxCount,
                        _locale_t      _Locale
    );
















































    




      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsdup" ". See online help for details."))
     wchar_t* __cdecl wcsdup(
          wchar_t const* _String
        );

    



    
    

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsicmp" ". See online help for details."))
     int __cdecl wcsicmp(
          wchar_t const* _String1,
          wchar_t const* _String2
        );

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsnicmp" ". See online help for details."))
     int __cdecl wcsnicmp(
          wchar_t const* _String1,
          wchar_t const* _String2,
                                size_t         _MaxCount
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsnset" ". See online help for details."))
     
     wchar_t* __cdecl wcsnset(
          wchar_t* _String,
                                  wchar_t  _Value,
                                  size_t   _MaxCount
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsrev" ". See online help for details."))
     
     wchar_t* __cdecl wcsrev(
          wchar_t* _String
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsset" ". See online help for details."))
     
     wchar_t* __cdecl wcsset(
          wchar_t* _String,
               wchar_t  _Value
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcslwr" ". See online help for details."))
     
     wchar_t* __cdecl wcslwr(
          wchar_t* _String
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsupr" ". See online help for details."))
     
     wchar_t* __cdecl wcsupr(
          wchar_t* _String
        );

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_wcsicoll" ". See online help for details."))
     int __cdecl wcsicoll(
          wchar_t const* _String1,
          wchar_t const* _String2
        );





__pragma(pack(pop))



#pragma warning(pop) 





#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )


__pragma(pack(push, 8))







    
     errno_t __cdecl strcpy_s(
          char*       _Destination,
                                  rsize_t     _SizeInBytes,
                                char const* _Source
        );

    
     errno_t __cdecl strcat_s(
          char*       _Destination,
                                     rsize_t     _SizeInBytes,
                                   char const* _Source
        );

    
     errno_t __cdecl strerror_s(
          char*  _Buffer,
                                  size_t _SizeInBytes,
                                  int    _ErrorNumber);

    
     errno_t __cdecl strncat_s(
          char*       _Destination,
                                     rsize_t     _SizeInBytes,
               char const* _Source,
                                     rsize_t     _MaxCount
        );

    
     errno_t __cdecl strncpy_s(
          char*       _Destination,
                                  rsize_t     _SizeInBytes,
            char const* _Source,
                                  rsize_t     _MaxCount
        );

     
     char*  __cdecl strtok_s(
                          char*       _String,
                                 char const* _Delimiter,
            char**      _Context
        );



 void* __cdecl _memccpy(
      void*       _Dst,
                                   void const* _Src,
                                   int         _Val,
                                   size_t      _MaxCount
    );





      char* __cdecl strcat( char *_Destination,  char const* _Source);



 
int __cdecl strcmp(
      char const* _Str1,
      char const* _Str2
    );

 
 int __cdecl _strcmpi(
      char const* _String1,
      char const* _String2
    );

 
 int __cdecl strcoll(
      char const* _String1,
      char const* _String2
    );

 
 int __cdecl _strcoll_l(
        char const* _String1,
        char const* _String2,
      _locale_t   _Locale
    );



  char* __cdecl strcpy( char *_Destination,  char const* _Source);

 
 size_t __cdecl strcspn(
      char const* _Str,
      char const* _Control
    );






 
 __declspec(allocator) char* __cdecl _strdup(
      char const* _Source
    );





 
 
  
 char*  __cdecl _strerror(
      char const* _ErrorMessage
    );


 errno_t __cdecl _strerror_s(
      char*       _Buffer,
                              size_t      _SizeInBytes,
                        char const* _ErrorMessage
    );



 
  
 char* __cdecl strerror(
      int _ErrorMessage
    );



 
 int __cdecl _stricmp(
      char const* _String1,
      char const* _String2
    );

 
 int __cdecl _stricoll(
      char const* _String1,
      char const* _String2
    );

 
 int __cdecl _stricoll_l(
        char const* _String1,
        char const* _String2,
      _locale_t   _Locale
    );

 
 int __cdecl _stricmp_l(
        char const* _String1,
        char const* _String2,
      _locale_t   _Locale
    );

 
size_t __cdecl strlen(
      char const* _Str
    );


 errno_t __cdecl _strlwr_s(
      char*  _String,
                          size_t _Size
    );



  char* __cdecl _strlwr( char *_String);


 errno_t __cdecl _strlwr_s_l(
      char*     _String,
                          size_t    _Size,
                      _locale_t _Locale
    );



  char* __cdecl _strlwr_l(  char *_String,   _locale_t _Locale);



  char* __cdecl strncat(  char *_Destination,   char const* _Source,   size_t _Count);

 
 int __cdecl strncmp(
      char const* _Str1,
      char const* _Str2,
                            size_t      _MaxCount
    );

 
 int __cdecl _strnicmp(
      char const* _String1,
      char const* _String2,
                            size_t      _MaxCount
    );

 
 int __cdecl _strnicmp_l(
      char const* _String1,
      char const* _String2,
                            size_t      _MaxCount,
                        _locale_t   _Locale
    );

 
 int __cdecl _strnicoll(
      char const* _String1,
      char const* _String2,
                            size_t      _MaxCount
    );

 
 int __cdecl _strnicoll_l(
      char const* _String1,
      char const* _String2,
                            size_t      _MaxCount,
                        _locale_t   _Locale
    );

 
 int __cdecl _strncoll(
      char const* _String1,
      char const* _String2,
                            size_t      _MaxCount
    );

 
 int __cdecl _strncoll_l(
      char const* _String1,
      char const* _String2,
                            size_t      _MaxCount,
                        _locale_t   _Locale
    );

 size_t __cdecl __strncnt(
      char const* _String,
                         size_t      _Count
    );



  char* __cdecl strncpy(    char *_Destination,   char const* _Source,   size_t _Count);

 


 size_t __cdecl strnlen(
      char const* _String,
                            size_t      _MaxCount
    );



     
    
    
    static __inline size_t __cdecl strnlen_s(
          char const* _String,
                                size_t      _MaxCount
        )
    {
        return _String == 0 ? 0 : strnlen(_String, _MaxCount);
    }




 errno_t __cdecl _strnset_s(
      char*  _String,
                                 size_t _SizeInBytes,
                                 int    _Value,
                                 size_t _MaxCount
    );



  char* __cdecl _strnset(  char *_Destination,   int _Value,   size_t _Count);

 
 char * __cdecl strpbrk(
      char const* _Str,
      char const* _Control
    );

 char* __cdecl _strrev(
      char* _Str
    );


 errno_t __cdecl _strset_s(
      char*  _Destination,
                                     size_t _DestinationSize,
                                     int    _Value
    );



  char* __cdecl _strset( char *_Destination,  int _Value);

 
 size_t __cdecl strspn(
      char const* _Str,
      char const* _Control
    );

  
 char* __cdecl strtok(
      char*       _String,
             char const* _Delimiter
    );


 errno_t __cdecl _strupr_s(
      char*  _String,
                          size_t _Size
    );



  char* __cdecl _strupr( char *_String);


 errno_t __cdecl _strupr_s_l(
      char*     _String,
                          size_t    _Size,
                      _locale_t _Locale
    );



  char* __cdecl _strupr_l(  char *_String,   _locale_t _Locale);

 

 size_t __cdecl strxfrm(
        char*       _Destination,
                                         char const* _Source,
                 size_t      _MaxCount
    );

 

 size_t __cdecl _strxfrm_l(
        char*       _Destination,
                                         char const* _Source,
                 size_t      _MaxCount,
                                       _locale_t   _Locale
    );




































    
    
      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strdup" ". See online help for details."))
     char* __cdecl strdup(
          char const* _String
        );
    

    
      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strcmpi" ". See online help for details."))
     int __cdecl strcmpi(
          char const* _String1,
          char const* _String2
        );

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_stricmp" ". See online help for details."))
     int __cdecl stricmp(
          char const* _String1,
          char const* _String2
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strlwr" ". See online help for details."))
     char* __cdecl strlwr(
          char* _String
        );

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strnicmp" ". See online help for details."))
     int __cdecl strnicmp(
          char const* _String1,
          char const* _String2,
                                size_t      _MaxCount
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strnset" ". See online help for details."))
     char* __cdecl strnset(
          char*  _String,
                                  int    _Value,
                                  size_t _MaxCount
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strrev" ". See online help for details."))
     char* __cdecl strrev(
          char* _String
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strset" ". See online help for details."))
    char* __cdecl strset(
          char* _String,
               int   _Value);

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_strupr" ". See online help for details."))
     char* __cdecl strupr(
          char* _String
        );





__pragma(pack(pop))

#pragma warning(pop) 












































































#pragma once



#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )



    

    typedef unsigned short _ino_t; 

    
        typedef _ino_t ino_t;
    





    

    typedef unsigned int _dev_t; 

    
        typedef _dev_t dev_t;
    





    

    typedef long _off_t; 

    
        typedef _off_t off_t;
    



#pragma warning(pop) 









#pragma once






#pragma warning(push)
#pragma warning(disable:   4514 4820 )

typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

typedef signed char        int_least8_t;
typedef short              int_least16_t;
typedef int                int_least32_t;
typedef long long          int_least64_t;
typedef unsigned char      uint_least8_t;
typedef unsigned short     uint_least16_t;
typedef unsigned int       uint_least32_t;
typedef unsigned long long uint_least64_t;

typedef signed char        int_fast8_t;
typedef int                int_fast16_t;
typedef int                int_fast32_t;
typedef long long          int_fast64_t;
typedef unsigned char      uint_fast8_t;
typedef unsigned int       uint_fast16_t;
typedef unsigned int       uint_fast32_t;
typedef unsigned long long uint_fast64_t;

typedef long long          intmax_t;
typedef unsigned long long uintmax_t;










































    
    
    












































#pragma warning(pop) 











#pragma once













#pragma once



#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )


__pragma(pack(push, 8))








struct tm
{
    int tm_sec;   
    int tm_min;   
    int tm_hour;  
    int tm_mday;  
    int tm_mon;   
    int tm_year;  
    int tm_wday;  
    int tm_yday;  
    int tm_isdst; 
};







  
 
 
 wchar_t* __cdecl _wasctime(
      struct tm const* _Tm
    );

 

 errno_t __cdecl _wasctime_s(
        wchar_t*         _Buffer,
                                          size_t           _SizeInWords,
                                                       struct tm const* _Tm
    );



 

 size_t __cdecl wcsftime(
       wchar_t*         _Buffer,
                               size_t           _SizeInWords,
                             wchar_t const*   _Format,
                               struct tm const* _Tm
    );

 

 size_t __cdecl _wcsftime_l(
       wchar_t*         _Buffer,
                               size_t           _SizeInWords,
                             wchar_t const*   _Format,
                               struct tm const* _Tm,
                           _locale_t        _Locale
    );

 
  
 wchar_t* __cdecl _wctime32(
      __time32_t const* _Time
    );


 errno_t __cdecl _wctime32_s(
        wchar_t*          _Buffer,
                                      size_t            _SizeInWords,
                                                       __time32_t const* _Time
    );



 
 
  
 wchar_t* __cdecl _wctime64(
      __time64_t const* _Time
    );


 errno_t __cdecl _wctime64_s(
        wchar_t*          _Buffer,
                                      size_t            _SizeInWords,
                                                       __time64_t const* _Time);




 errno_t __cdecl _wstrdate_s(
       wchar_t* _Buffer,
                                                                                size_t   _SizeInWords
    );



   wchar_t* __cdecl _wstrdate( wchar_t *_Buffer);


 errno_t __cdecl _wstrtime_s(
       wchar_t* _Buffer,
                                                                                size_t   _SizeInWords
    );



   wchar_t* __cdecl _wstrtime( wchar_t *_Buffer);









    




















         
        static __inline wchar_t * __cdecl _wctime(
              time_t const* const _Time)
        {
            return _wctime64(_Time);
        }

        
        static __inline errno_t __cdecl _wctime_s(
                  wchar_t*      const _Buffer,
                                                             size_t        const _SizeInWords,
                                                             time_t const* const _Time
            )
        {
            return _wctime64_s(_Buffer, _SizeInWords, _Time);
        }

    


__pragma(pack(pop))

#pragma warning(pop) 


#pragma warning(push)
#pragma warning(disable: 4324  4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )


__pragma(pack(push, 8))










typedef long clock_t;

struct _timespec32
{
    __time32_t tv_sec;
    long       tv_nsec;
};

struct _timespec64
{
    __time64_t tv_sec;
    long       tv_nsec;
};


    struct timespec
    {
        time_t tv_sec;  
        long   tv_nsec; 
    };

















  
 int* __cdecl __daylight(void);




  
 long* __cdecl __dstbias(void);




  
 long* __cdecl __timezone(void);




    
 char** __cdecl __tzname(void);



  
 errno_t __cdecl _get_daylight(
      int* _Daylight
    );

 
 errno_t __cdecl _get_dstbias(
      long* _DaylightSavingsBias
    );

  
 errno_t __cdecl _get_timezone(
      long* _TimeZone
    );

 
 errno_t __cdecl _get_tzname(
                             size_t* _ReturnValue,
      char*   _Buffer,
                              size_t  _SizeInBytes,
                              int     _Index
    );








 
 
  
 char* __cdecl asctime(
      struct tm const* _Tm
    );


     
    
     errno_t __cdecl asctime_s(
            char*            _Buffer,
                                            size_t           _SizeInBytes,
                                                         struct tm const* _Tm
        );




 
 clock_t __cdecl clock(void);

 
 
  
 char* __cdecl _ctime32(
      __time32_t const* _Time
    );


 errno_t __cdecl _ctime32_s(
        char*             _Buffer,
                                        size_t            _SizeInBytes,
                                                     __time32_t const* _Time
    );



 
 
  
 char* __cdecl _ctime64(
      __time64_t const* _Time
    );


 errno_t __cdecl _ctime64_s(
        char*             _Buffer,
                                          size_t            _SizeInBytes,
                                                       __time64_t const* _Time
    );



 
 double __cdecl _difftime32(
      __time32_t _Time1,
      __time32_t _Time2
    );

 
 double __cdecl _difftime64(
      __time64_t _Time1,
      __time64_t _Time2
    );

 
  
 struct tm* __cdecl _gmtime32(
      __time32_t const* _Time
    );


 errno_t __cdecl _gmtime32_s(
      struct tm*        _Tm,
       __time32_t const* _Time
    );

 
  
 struct tm* __cdecl _gmtime64(
      __time64_t const* _Time
    );


 errno_t __cdecl _gmtime64_s(
      struct tm*        _Tm,
       __time64_t const* _Time
    );

 
  
 struct tm* __cdecl _localtime32(
      __time32_t const* _Time
    );


 errno_t __cdecl _localtime32_s(
      struct tm*        _Tm,
       __time32_t const* _Time
    );

 
  
 struct tm* __cdecl _localtime64(
      __time64_t const* _Time
    );


 errno_t __cdecl _localtime64_s(
      struct tm*        _Tm,
       __time64_t const* _Time
    );

 
 __time32_t __cdecl _mkgmtime32(
      struct tm* _Tm
    );

 
 __time64_t __cdecl _mkgmtime64(
      struct tm* _Tm
    );


 __time32_t __cdecl _mktime32(
      struct tm* _Tm
    );


 __time64_t __cdecl _mktime64(
      struct tm* _Tm
    );

 

 size_t __cdecl strftime(
       char*            _Buffer,
                               size_t           _SizeInBytes,
        char const*      _Format,
                               struct tm const* _Tm
    );

 

 size_t __cdecl _strftime_l(
           char*            _Buffer,
                               size_t           _MaxSize,
        char const*      _Format,
                               struct tm const* _Tm,
                           _locale_t        _Locale
    );


 errno_t __cdecl _strdate_s(
       char*  _Buffer,
                                                                              size_t _SizeInBytes
    );



   char* __cdecl _strdate( char *_Buffer);


 errno_t __cdecl _strtime_s(
       char*  _Buffer,
                                                                              size_t _SizeInBytes
    );



  char* __cdecl _strtime( char *_Buffer);

 __time32_t __cdecl _time32(
      __time32_t* _Time
    );

 __time64_t __cdecl _time64(
      __time64_t* _Time
    );

 
 
 int __cdecl _timespec32_get(
      struct _timespec32* _Ts,
       int                 _Base
    );

 
 
 int __cdecl _timespec64_get(
      struct _timespec64* _Ts,
       int                 _Base
    );










     void __cdecl _tzset(void);

    
    __declspec(deprecated("This function or variable has been superceded by newer library " "or operating system functionality. Consider using " "GetLocalTime" " " "instead. See online help for details."))
     unsigned __cdecl _getsystime(
          struct tm* _Tm
        );

    __declspec(deprecated("This function or variable has been superceded by newer library " "or operating system functionality. Consider using " "SetLocalTime" " " "instead. See online help for details."))
     unsigned __cdecl _setsystime(
          struct tm* _Tm,
          unsigned   _Milliseconds
        );












    






























































































































          
        static __inline char* __cdecl ctime(
              time_t const* const _Time
            )
        {
            return _ctime64(_Time);
        }

         
        static __inline double __cdecl difftime(
              time_t const _Time1,
              time_t const _Time2
            )
        {
            return _difftime64(_Time1, _Time2);
        }

          
        static __inline struct tm* __cdecl gmtime(
              time_t const* const _Time)
        {
            return _gmtime64(_Time);
        }

        
        static __inline struct tm* __cdecl localtime(
              time_t const* const _Time
            )
        {
            return _localtime64(_Time);
        }

         
        static __inline time_t __cdecl _mkgmtime(
              struct tm* const _Tm
            )
        {
            return _mkgmtime64(_Tm);
        }

        
        static __inline time_t __cdecl mktime(
              struct tm* const _Tm
            )
        {
            return _mktime64(_Tm);
        }

        static __inline time_t __cdecl time(
              time_t* const _Time
            )
        {
            return _time64(_Time);
        }

         
        static __inline int __cdecl timespec_get(
              struct timespec* const _Ts,
               int              const _Base
            )
        {
            return _timespec64_get((struct _timespec64*)_Ts, _Base);
        }

        
            
            static __inline errno_t __cdecl ctime_s(
                    char*         const _Buffer,
                                                    size_t        const _SizeInBytes,
                                                                 time_t const* const _Time
                )
            {
                return _ctime64_s(_Buffer, _SizeInBytes, _Time);
            }

        


























            
            static __inline errno_t __cdecl gmtime_s(
                      struct tm*    const _Tm,
                       time_t const* const _Time
                )
            {
                return _gmtime64_s(_Tm, _Time);
            }

            
                static __inline errno_t __cdecl localtime_s(
                      struct tm*    const _Tm,
                       time_t const* const _Time
                )
            {
                return _localtime64_s(_Tm, _Time);
            }
        
        

    












    

    
        __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C " "and C++ conformant name: " "_tzset" ". See online help for details."))  void __cdecl tzset(void);
    





__pragma(pack(pop))

#pragma warning(pop) 







typedef int clockid_t;

















typedef enum {
    INTEL_DEVICE_I210,
    INTEL_DEVICE_I219,
    INTEL_DEVICE_I225,
    INTEL_DEVICE_I226,
    INTEL_DEVICE_UNKNOWN
} intel_device_type_t;


struct resource {
    uint64_t paddr;
    uint32_t mmap_size;
};





struct intel_packet {
    struct resource map;        
    unsigned int offset;        
    void *vaddr;
    uint32_t len;
    uint32_t flags;
    uint64_t attime;          
    uint64_t dmatime;         
    struct intel_packet *next;  
};


typedef struct _device_t {
    void *private_data;
    uint16_t pci_vendor_id;
    uint16_t pci_device_id;
    uint16_t domain;
    uint8_t bus;
    uint8_t dev;
    uint8_t func;
    intel_device_type_t device_type;
    uint32_t capabilities;
} device_t;


struct intel_dma_alloc {
    uint64_t dma_paddr;
    void *dma_vaddr;
    unsigned int mmap_size;
};


struct tsn_tas_config {
    uint64_t base_time_s;      
    uint32_t base_time_ns;     
    uint32_t cycle_time_s;     
    uint32_t cycle_time_ns;    
    uint8_t gate_states[8];    
    uint32_t gate_durations[8]; 
};

struct tsn_fp_config {
    uint8_t preemptable_queues; 
    uint32_t min_fragment_size; 
    uint8_t verify_disable;     
};


struct ptm_config {
    uint8_t enabled;           
    uint32_t clock_granularity; 
};


int intel_probe(device_t *dev);
int intel_attach(char *dev_path, device_t *pdev);
int intel_attach_rx(device_t *pdev);
int intel_attach_tx(device_t *pdev);
int intel_detach(device_t *dev);
int intel_init(device_t *dev);


int intel_dma_malloc_page(device_t *dev, struct intel_dma_alloc *page);
void intel_dma_free_page(device_t *dev, struct intel_dma_alloc *page);


int intel_xmit(device_t *dev, unsigned int queue_index, struct intel_packet *packet);
int intel_refresh_buffers(device_t *dev, uint32_t idx,
                         struct intel_packet **rxbuf_packets, uint32_t num_bufs);
int intel_receive(device_t *dev, unsigned int queue_index, 
                 struct intel_packet **received_packets, uint32_t *count);
void intel_clean(device_t *dev, struct intel_packet **cleaned_packets);


int intel_get_wallclock(device_t *dev, uint64_t *curtime, uint64_t *rdtsc);
int intel_gettime(device_t *dev, clockid_t clk_id, uint64_t *curtime,
                 struct timespec *system_time);
int intel_get_systime(device_t *dev, uint64_t *systime);
int intel_set_systime(device_t *dev, uint64_t systime);
int intel_adjust_systime(device_t *dev, int32_t ppb);


int intel_setup_time_aware_shaper(device_t *dev, struct tsn_tas_config *config);
int intel_setup_frame_preemption(device_t *dev, struct tsn_fp_config *config);
int intel_setup_ptm(device_t *dev, struct ptm_config *config);


int intel_read_reg(device_t *dev, uint32_t offset, uint32_t *value);
int intel_write_reg(device_t *dev, uint32_t offset, uint32_t value);


int intel_mdio_read(device_t *dev, uint32_t page, uint32_t reg, uint16_t *value);
int intel_mdio_write(device_t *dev, uint32_t page, uint32_t reg, uint16_t value);


int intel_get_device_info(device_t *dev, char *info_buffer, size_t buffer_size);
uint32_t intel_get_capabilities(device_t *dev);
const char *intel_get_device_name(device_t *dev);
int intel_has_capability(device_t *dev, uint32_t capability);















































struct intel_private {
    intel_device_type_t device_type;
    uint32_t capabilities;
    int initialized;
    
    
    void *mmio_base;
    size_t mmio_size;
    
    
    int (*read_reg)(struct intel_private *priv, uint32_t offset, uint32_t *value);
    int (*write_reg)(struct intel_private *priv, uint32_t offset, uint32_t value);
    int (*get_systime)(struct intel_private *priv, uint64_t *systime);
    int (*set_systime)(struct intel_private *priv, uint64_t systime);
    int (*adjust_systime)(struct intel_private *priv, int32_t ppb);
    
    
    int (*setup_tas)(struct intel_private *priv, struct tsn_tas_config *config);
    int (*setup_fp)(struct intel_private *priv, struct tsn_fp_config *config);
    int (*setup_ptm)(struct intel_private *priv, struct ptm_config *config);
    
    
    int (*mdio_read)(struct intel_private *priv, uint32_t page, uint32_t reg, uint16_t *value);
    int (*mdio_write)(struct intel_private *priv, uint32_t page, uint32_t reg, uint16_t value);
    
    
    void *device_private;
};
















































int intel_common_init(device_t *dev);
void intel_common_cleanup(device_t *dev);
int intel_has_capability(device_t *dev, uint32_t capability);
int intel_validate_packet(struct intel_packet *packet);


int intel_i210_init(device_t *dev);
int intel_i219_init(device_t *dev);
int intel_i225_init(device_t *dev);
int intel_i226_init(device_t *dev);


void intel_i210_cleanup(device_t *dev);
void intel_i219_cleanup(device_t *dev);
void intel_i225_cleanup(device_t *dev);
void intel_i226_cleanup(device_t *dev);
















struct intel_device_info {
    uint16_t device_id;
    intel_device_type_t device_type;
    uint32_t capabilities;
    const char *name;
    const char *description;
};

static const struct intel_device_info intel_devices[] = {
    
    { 0x1533, INTEL_DEVICE_I210, 
      (1 << 0) | (1 << 7),
      "I210", "Intel I210 Gigabit Network Connection" },
    { 0x1536, INTEL_DEVICE_I210, 
      (1 << 0) | (1 << 7),
      "I210-T1", "Intel I210-T1 Gigabit Network Connection" },
    { 0x1537, INTEL_DEVICE_I210, 
      (1 << 0) | (1 << 7),
      "I210-IS", "Intel I210-IS Gigabit Network Connection" },
    
    
    { 0x15b7, INTEL_DEVICE_I219, 
      (1 << 0) | (1 << 6),
      "I219-LM", "Intel I219-LM Gigabit Network Connection" },
    { 0x15b8, INTEL_DEVICE_I219, 
      (1 << 0) | (1 << 6),
      "I219-V", "Intel I219-V Gigabit Network Connection" },
    { 0x15d6, INTEL_DEVICE_I219, 
      (1 << 0) | (1 << 6),
      "I219-V", "Intel I219-V Gigabit Network Connection" },
    { 0x15d7, INTEL_DEVICE_I219, 
      (1 << 0) | (1 << 6),
      "I219-LM", "Intel I219-LM Gigabit Network Connection" },
    { 0x15d8, INTEL_DEVICE_I219, 
      (1 << 0) | (1 << 6),
      "I219-V", "Intel I219-V Gigabit Network Connection" },
    { 0x0dc7, INTEL_DEVICE_I219, 
      (1 << 0) | (1 << 6),
      "I219-LM", "Intel I219-LM Gigabit Network Connection (22)" },
    
    
    { 0x15f2, INTEL_DEVICE_I225, 
      (1 << 0) | (1 << 1) | (1 << 2) | 
      (1 << 3) | (1 << 4) | (1 << 5) | (1 << 7),
      "I225-LM", "Intel I225-LM 2.5 Gigabit Network Connection" },
    { 0x15f3, INTEL_DEVICE_I225, 
      (1 << 0) | (1 << 1) | (1 << 2) | 
      (1 << 3) | (1 << 4) | (1 << 5) | (1 << 7),
      "I225-V", "Intel I225-V 2.5 Gigabit Network Connection" },
    
    
    { 0x125b, INTEL_DEVICE_I226, 
      (1 << 0) | (1 << 1) | (1 << 2) | 
      (1 << 3) | (1 << 4) | (1 << 5) | (1 << 7),
      "I226-LM", "Intel I226-LM 2.5 Gigabit Network Connection" },
    { 0x125c, INTEL_DEVICE_I226, 
      (1 << 0) | (1 << 1) | (1 << 2) | 
      (1 << 3) | (1 << 4) | (1 << 5) | (1 << 7),
      "I226-V", "Intel I226-V 2.5 Gigabit Network Connection" },
    
    
    { 0, INTEL_DEVICE_UNKNOWN, 0, ((void *)0), ((void *)0) }
};




static const struct intel_device_info *intel_identify_device(uint16_t device_id)
{
    const struct intel_device_info *info;
    
    for (info = intel_devices; info->device_id != 0; info++) {
        if (info->device_id == device_id) {
            return info;
        }
    }
    
    return ((void *)0);
}




int intel_probe(device_t *dev)
{
    const struct intel_device_info *info;
    
    if (!dev) {
        return -22;
    }
    
    
    if (dev->pci_vendor_id != 0x8086) {
        return -19;
    }
    
    
    info = intel_identify_device(dev->pci_device_id);
    if (!info) {
        return -19;
    }
    
    
    dev->device_type = info->device_type;
    dev->capabilities = info->capabilities;
    
    return 0;
}




uint32_t intel_get_capabilities(device_t *dev)
{
    if (!dev) {
        return 0;
    }
    
    return dev->capabilities;
}




const char *intel_get_device_name(device_t *dev)
{
    const struct intel_device_info *info;
    
    if (!dev) {
        return "Unknown";
    }
    
    info = intel_identify_device(dev->pci_device_id);
    if (!info) {
        return "Unknown Intel Device";
    }
    
    return info->name;
}




int intel_get_device_info(device_t *dev, char *info_buffer, size_t buffer_size)
{
    const struct intel_device_info *info;
    int ret;
    
    if (!dev || !info_buffer) {
        return -22;
    }
    
    info = intel_identify_device(dev->pci_device_id);
    if (!info) {
        ret = snprintf(info_buffer, buffer_size, 
                      "Unknown Intel Device (ID: 0x%04x)", dev->pci_device_id);
    } else {
        ret = snprintf(info_buffer, buffer_size, 
                      "%s - %s (ID: 0x%04x, Caps: 0x%08x)", 
                      info->name, info->description, 
                      dev->pci_device_id, dev->capabilities);
    }
    
    return (ret >= (int)buffer_size) ? -28 : 0;
}




int intel_has_capability(device_t *dev, uint32_t capability)
{
    if (!dev) {
        return 0;
    }
    
    return (dev->capabilities & capability) != 0;
}




int intel_common_init(device_t *dev)
{
    struct intel_private *priv;
    
    if (!dev) {
        return -22;
    }
    
    
    priv = calloc(1, sizeof(struct intel_private));
    if (!priv) {
        return -12;
    }
    
    
    priv->device_type = dev->device_type;
    priv->capabilities = dev->capabilities;
    priv->initialized = 1;
    
    dev->private_data = priv;
    
    return 0;
}




void intel_common_cleanup(device_t *dev)
{
    struct intel_private *priv;
    
    if (!dev || !dev->private_data) {
        return;
    }
    
    priv = (struct intel_private *)dev->private_data;
    priv->initialized = 0;
    
    free(dev->private_data);
    dev->private_data = ((void *)0);
}




int intel_validate_packet(struct intel_packet *packet)
{
    if (!packet) {
        return -22;
    }
    
    if (!packet->vaddr || packet->len == 0) {
        return -22;
    }
    
    
    if (packet->len > 9000) { 
        return -115;
    }
    
    return 0;
}
