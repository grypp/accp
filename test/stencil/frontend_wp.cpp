/* HMPP global lookup function */
static struct hmpprti_grouplet * hmppsi_lookup(void);


typedef long int  ptrdiff_t;
typedef long unsigned int  size_t;
typedef int  wchar_t;
struct hmpprti_grouplet  *hmpprti_lookup_grouplet(const char *grouplet_name);


void  hmpprti_set_property(const char *name, const char *value);



int  hmpprti_is_initialized(const struct hmpprti_grouplet *grouplet);


void  hmpprti_set_initialized(struct hmpprti_grouplet *grouplet, int initialized);



void  hmpprti_append_target(struct hmpprti_grouplet *grouplet, const char *target_name);



void  hmpprti_append_buffer(struct hmpprti_grouplet *grouplet, const char *buffer_name, size_t element_size, int dimension_count, int dynamic, int lazy_transfer_at_callsite, int load_once_between_two_allocates);








void  hmpprti_append_codelet(struct hmpprti_grouplet *grouplet, const char *codelet_name, const char *function_name);




void  hmpprti_append_buffer_to_codelet(struct hmpprti_grouplet *grouplet, int codelet_index, int buffer_index, int load_before_callsite, int store_after_callsite);






void  hmpprti_append_buffer_to_codelet_hmpp2(struct hmpprti_grouplet *grouplet, int codelet_index, int buffer_index);




struct hmpprti_grouplet  *hmpprti_push_acquire(struct hmpprti_grouplet *grouplet, int default_device, int device, int exclusive);





struct hmpprti_grouplet  *hmpprti_push_release(struct hmpprti_grouplet *grouplet, int default_device, int device);




struct hmpprti_grouplet  *hmpprti_push_free_all(struct hmpprti_grouplet *grouplet);


struct hmpprti_grouplet  *hmpprti_push_allocate(struct hmpprti_grouplet *grouplet, int buffer_index, int ignore_unbound, int default_device, int device, int dimension_count,  ...);








struct hmpprti_grouplet  *hmpprti_push_free(struct hmpprti_grouplet *grouplet, int buffer_index, int ignore_unbound);




struct hmpprti_grouplet  *hmpprti_push_bind(struct hmpprti_grouplet *grouplet, int buffer_index, const char *address_string);




struct hmpprti_grouplet  *hmpprti_push_load(struct hmpprti_grouplet *grouplet, int buffer_index, int async, int slice_count,  ...);






struct hmpprti_grouplet  *hmpprti_push_wait_load(struct hmpprti_grouplet *grouplet, int buffer_index);



struct hmpprti_grouplet  *hmpprti_push_store(struct hmpprti_grouplet *grouplet, int buffer_index, int async, int slice_count,  ...);






struct hmpprti_grouplet  *hmpprti_push_wait_store(struct hmpprti_grouplet *grouplet, int buffer_index);



struct hmpprti_grouplet  *hmpprti_push_callsite(struct hmpprti_grouplet *grouplet, int codelet_index, int async);




struct hmpprti_grouplet  *hmpprti_push_callsite_hmpp2(struct hmpprti_grouplet *grouplet, int codelet_index, int async, int argument_count,  ...);






struct hmpprti_grouplet  *hmpprti_push_standalone_callsite(struct hmpprti_grouplet *grouplet, const char *function_name, int argument_count);




struct hmpprti_grouplet  *hmpprti_push_synchronize(struct hmpprti_grouplet *grouplet, int codelet_index);



struct hmpprti_grouplet  *hmpprti_push_host_read(struct hmpprti_grouplet *grouplet, int buffer_index);



struct hmpprti_grouplet  *hmpprti_push_host_write(struct hmpprti_grouplet *grouplet, int buffer_index);



struct hmpprti_grouplet  *hmpprti_push_allocate_mirror(struct hmpprti_grouplet *grouplet, const char *address_string, int default_device, int device, size_t element_size, int dimension_count,  ...);








struct hmpprti_grouplet  *hmpprti_push_free_mirror(struct hmpprti_grouplet *grouplet, const char *address_string);



struct hmpprti_grouplet  *hmpprti_push_load_mirror(struct hmpprti_grouplet *grouplet, const char *address_string, int async, int slice_count,  ...);






struct hmpprti_grouplet  *hmpprti_push_wait_load_mirror(struct hmpprti_grouplet *grouplet, const char *address_string);



struct hmpprti_grouplet  *hmpprti_push_store_mirror(struct hmpprti_grouplet *grouplet, const char *address_string, int async, int slice_count,  ...);






struct hmpprti_grouplet  *hmpprti_push_wait_store_mirror(struct hmpprti_grouplet *grouplet, const char *address_string);



void  hmpprti_run_directive(struct hmpprti_grouplet *grouplet, int *error, const char *file_name, int line_number, int semantic,  ...);







void  hmpprti_enqueue_directive(struct hmpprti_grouplet *grouplet, const char *file_name, int line_number, int semantic,  ...);






void  hmpprti_run_queue(int *error);


void  hmpprti_use_cuda_uva(int use);
void  openacci_call(const char *file_name, int line_number, const char *function_name);




void  openacci_fallback(const char *file_name, int line_number, const char *function_name);




void  openacci_enter_region(const char *file_name, int line_number, int region_kind, int num_args, int async_mode, int queue_id);







void  openacci_leave_region(const char *file_name, int line_number);



void  openacci_push_data(const char *file_name, int line_number, const char *variable_name, const void *host_address, size_t start, size_t length, size_t element_size, int transfer_mode);









void  openacci_update_datas(const char *file_name, int line_number, int nb_variables, const char **variable_names, const void **host_addresses, size_t *starts, size_t *lengths, size_t *elements_sizes, int *update_sides, int async_mode, int queue_id);
void  openacci_update_data(const char *file_name, int line_number, const char *variable_name, const void *host_address, size_t start, size_t length, size_t element_size, int update_side, int async_mode, int queue_id);
void  openacci_wait(const char *file_name, int line_number, int async_mode, int queue_id);





void  *openacci_get_device_pointer(const char *file_name, int line_number, const void *host_address);
typedef unsigned char  __u_char;
typedef unsigned short int  __u_short;
typedef unsigned int  __u_int;
typedef unsigned long int  __u_long;


typedef signed char  __int8_t;
typedef unsigned char  __int;
typedef signed short int  __int16_t;
typedef unsigned short int  __uint16_t;
typedef signed int  __int32_t;
typedef unsigned int  __uint32_t;

typedef signed long int  __int64_t;
typedef unsigned long int  __uint64_t;







typedef long int  __quad_t;
typedef unsigned long int  __u_quad_t;
typedef unsigned long int  __dev_t;
typedef unsigned int  __uid_t;
typedef unsigned int  __gid_t;
typedef unsigned long int  __ino_t;
typedef unsigned long int  __ino64_t;
typedef unsigned int  __mode_t;
typedef unsigned long int  __nlink_t;
typedef long int  __off_t;
typedef long int  __off64_t;
typedef int  __pid_t;
typedef  struct __belooga_anonymous_type__292{  int  __val[2];
} __fsid_t;typedef long int  __clock_t;
typedef unsigned long int  __rlim_t;
typedef unsigned long int  __rlim64_t;
typedef unsigned int  __id_t;
typedef long int  __time_t;
typedef unsigned int  __useconds_t;
typedef long int  __suseconds_t;

typedef int  __daddr_t;
typedef long int  __swblk_t;
typedef int  __key_t;


typedef int  __clockid_t;


typedef void  *__timer_t;


typedef long int  __blksize_t;




typedef long int  __blkcnt_t;
typedef long int  __blkcnt64_t;


typedef unsigned long int  __fsblkcnt_t;
typedef unsigned long int  __fsblkcnt64_t;


typedef unsigned long int  __fsfilcnt_t;
typedef unsigned long int  __fsfilcnt64_t;

typedef long int  __ssize_t;



typedef __off64_t  __loff_t;
typedef __quad_t  *__qaddr_t;
typedef char  *__caddr_t;


typedef long int  __intptr_t;


typedef unsigned int  __socklen_t;
struct _IO_FILE  ;



typedef struct _IO_FILE  FILE;
typedef struct _IO_FILE  __FILE;
typedef  struct __belooga_anonymous_type__352{

  int  __count;
   union __belooga_anonymous_type__353{


    unsigned int  __wch;



    char  __wchb[4];
  } __value;
} __mbstate_t;
typedef  struct __belooga_anonymous_type__357{

  __off_t  __pos;
  __mbstate_t  __state;
} _G_fpos_t;
typedef  struct __belooga_anonymous_type__361{

  __off64_t  __pos;
  __mbstate_t  __state;
} _G_fpos64_t;
typedef int  _G_int16_t __attribute__((__mode__ (__HI__))) ;
typedef int  _G_int32_t __attribute__((__mode__ (__SI__))) ;
typedef unsigned int  _G_uint16_t __attribute__((__mode__ (__HI__))) ;
typedef unsigned int  _G_uint32_t __attribute__((__mode__ (__SI__))) ;
typedef  __builtin_va_list __gnuc_va_list;
struct _IO_jump_t  ;struct _IO_FILE  ;









typedef void  _IO_lock_t;





 struct _IO_marker{
  struct _IO_marker  *_next;
  struct _IO_FILE  *_sbuf;



  int  _pos;
} ;
 enum __codecvt_result{

__codecvt_ok, __codecvt_partial, __codecvt_error, __codecvt_noconv}
;
 struct _IO_FILE{
  int  _flags;




  char  *_IO_read_ptr;
  char  *_IO_read_end;
  char  *_IO_read_base;
  char  *_IO_write_base;
  char  *_IO_write_ptr;
  char  *_IO_write_end;
  char  *_IO_buf_base;
  char  *_IO_buf_end;

  char  *_IO_save_base;
  char  *_IO_backup_base;
  char  *_IO_save_end;

  struct _IO_marker  *_markers;

  struct _IO_FILE  *_chain;

  int  _fileno;



  int  _flags2;

  __off_t  _old_offset;



  unsigned short  _cur_column;
  signed char  _vtable_offset;
  char  _shortbuf[1];



  _IO_lock_t  *_lock;








  __off64_t  _offset;








  void  *__pad1;
  void  *__pad2;
  void  *__pad3;
  void  *__pad4;
  size_t  __pad5;

  int  _mode;

  char  _unused2[15 * sizeof (int ) - 4 * sizeof (void *) - sizeof (size_t )];
} ;



typedef struct _IO_FILE  _IO_FILE;


struct _IO_FILE_plus  ;

extern struct _IO_FILE_plus  _IO_2_1_stdin_;
extern struct _IO_FILE_plus  _IO_2_1_stdout_;
extern struct _IO_FILE_plus  _IO_2_1_stderr_;
typedef __ssize_t  __io_read_fn(void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t  __io_write_fn(void *__cookie, __const char *__buf, size_t __n);








typedef int  __io_seek_fn(void *__cookie, __off64_t *__pos, int __w);


typedef int  __io_close_fn(void *__cookie);
extern int  __underflow(_IO_FILE *);
extern int  __uflow(_IO_FILE *);
extern int  __overflow(_IO_FILE *, int );
extern int  _IO_getc(_IO_FILE *__fp);
extern int  _IO_putc(int __c, _IO_FILE *__fp);
extern int  _IO_feof(_IO_FILE *__fp) __attribute__((__nothrow__)) ;
extern int  _IO_ferror(_IO_FILE *__fp) __attribute__((__nothrow__)) ;

extern int  _IO_peekc_locked(_IO_FILE *__fp);





extern void  _IO_flockfile(_IO_FILE *) __attribute__((__nothrow__)) ;
extern void  _IO_funlockfile(_IO_FILE *) __attribute__((__nothrow__)) ;
extern int  _IO_ftrylockfile(_IO_FILE *) __attribute__((__nothrow__)) ;
extern int  _IO_vfscanf(_IO_FILE *__restrict , const char *__restrict , __gnuc_va_list , int *__restrict );

extern int  _IO_vfprintf(_IO_FILE *__restrict , const char *__restrict , __gnuc_va_list );

extern __ssize_t  _IO_padn(_IO_FILE *, int , __ssize_t );
extern size_t  _IO_sgetn(_IO_FILE *, void *, size_t );

extern __off64_t  _IO_seekoff(_IO_FILE *, __off64_t , int , int );
extern __off64_t  _IO_seekpos(_IO_FILE *, __off64_t , int );

extern void  _IO_free_backup_area(_IO_FILE *) __attribute__((__nothrow__)) ;
typedef __gnuc_va_list  va_list;










typedef __off_t  off_t;
typedef __ssize_t  ssize_t;







typedef _G_fpos_t  fpos_t;
extern struct _IO_FILE  *stdin;
extern struct _IO_FILE  *stdout;
extern struct _IO_FILE  *stderr;









extern int  remove(__const char *__filename) __attribute__((__nothrow__)) ;

extern int  rename(__const char *__old, __const char *__new) __attribute__((__nothrow__)) ;




extern int  renameat(int __oldfd, __const char *__old, int __newfd, __const char *__new) __attribute__((__nothrow__)) ;









extern FILE  *tmpfile(void );
extern char  *tmpnam(char *__s) __attribute__((__nothrow__)) ;





extern char  *tmpnam_r(char *__s) __attribute__((__nothrow__)) ;
extern char  *tempnam(__const char *__dir, __const char *__pfx) __attribute__((__nothrow__))  __attribute__((__malloc__)) ;









extern int  fclose(FILE *__stream);




extern int  fflush(FILE *__stream);









extern int  fflush_unlocked(FILE *__stream);
extern FILE  *fopen(__const char *__restrict __filename, __const char *__restrict __modes);





extern FILE  *freopen(__const char *__restrict __filename, __const char *__restrict __modes, FILE *__restrict __stream);
extern FILE  *fdopen(int __fd, __const char *__modes) __attribute__((__nothrow__)) ;
extern FILE  *fmemopen(void *__s, size_t __len, __const char *__modes) __attribute__((__nothrow__)) ;





extern FILE  *open_memstream(char **__bufloc, size_t *__sizeloc) __attribute__((__nothrow__)) ;






extern void  setbuf(FILE *__restrict __stream, char *__restrict __buf) __attribute__((__nothrow__)) ;



extern int  setvbuf(FILE *__restrict __stream, char *__restrict __buf, int __modes, size_t __n) __attribute__((__nothrow__)) ;






extern void  setbuffer(FILE *__restrict __stream, char *__restrict __buf, size_t __size) __attribute__((__nothrow__)) ;



extern void  setlinebuf(FILE *__stream) __attribute__((__nothrow__)) ;








extern int  fprintf(FILE *__restrict __stream, __const char *__restrict __format,  ...);





extern int  printf(__const char *__restrict __format,  ...);

extern int  sprintf(char *__restrict __s, __const char *__restrict __format,  ...) __attribute__((__nothrow__)) ;






extern int  vfprintf(FILE *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg);





extern int  vprintf(__const char *__restrict __format, __gnuc_va_list __arg);

extern int  vsprintf(char *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __attribute__((__nothrow__)) ;






extern int  snprintf(char *__restrict __s, size_t __maxlen, __const char *__restrict __format,  ...) __attribute__((__nothrow__))  __attribute__((__format__ (__printf__, 3, 4))) ;



extern int  vsnprintf(char *__restrict __s, size_t __maxlen, __const char *__restrict __format, __gnuc_va_list __arg) __attribute__((__nothrow__))  __attribute__((__format__ (__printf__, 3, 0))) ;
extern int  vdprintf(int __fd, __const char *__restrict __fmt, __gnuc_va_list __arg) __attribute__((__format__ (__printf__, 2, 0))) ;


extern int  dprintf(int __fd, __const char *__restrict __fmt,  ...) __attribute__((__format__ (__printf__, 2, 3))) ;









extern int  fscanf(FILE *__restrict __stream, __const char *__restrict __format,  ...);





extern int  scanf(__const char *__restrict __format,  ...);

extern int  sscanf(__const char *__restrict __s, __const char *__restrict __format,  ...) __attribute__((__nothrow__)) ;









extern int  fscanf(FILE *__restrict __stream, __const char *__restrict __format,  ...) __asm__ ("__isoc99_fscanf");


extern int  scanf(__const char *__restrict __format,  ...) __asm__ ("__isoc99_scanf");

extern int  sscanf(__const char *__restrict __s, __const char *__restrict __format,  ...) __asm__ ("__isoc99_sscanf") __attribute__((__nothrow__)) ;
extern int  vfscanf(FILE *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __attribute__((__format__ (__scanf__, 2, 0))) ;







extern int  vscanf(__const char *__restrict __format, __gnuc_va_list __arg) __attribute__((__format__ (__scanf__, 1, 0))) ;



extern int  vsscanf(__const char *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __attribute__((__nothrow__))  __attribute__((__format__ (__scanf__, 2, 0))) ;










extern int  vfscanf(FILE *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("__isoc99_vfscanf") __attribute__((__format__ (__scanf__, 2, 0))) ;




extern int  vscanf(__const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("__isoc99_vscanf") __attribute__((__format__ (__scanf__, 1, 0))) ;


extern int  vsscanf(__const char *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("__isoc99_vsscanf") __attribute__((__nothrow__))  __attribute__((__format__ (__scanf__, 2, 0))) ;
extern int  fgetc(FILE *__stream);
extern int  getc(FILE *__stream);





extern int  getchar(void );
extern int  getc_unlocked(FILE *__stream);
extern int  getchar_unlocked(void );









extern int  fgetc_unlocked(FILE *__stream);
extern int  fputc(int __c, FILE *__stream);
extern int  putc(int __c, FILE *__stream);





extern int  putchar(int __c);
extern int  fputc_unlocked(int __c, FILE *__stream);







extern int  putc_unlocked(int __c, FILE *__stream);
extern int  putchar_unlocked(int __c);






extern int  getw(FILE *__stream);


extern int  putw(int __w, FILE *__stream);








extern char  *fgets(char *__restrict __s, int __n, FILE *__restrict __stream);







extern char  *gets(char *__s);
extern __ssize_t  __getdelim(char **__restrict __lineptr, size_t *__restrict __n, int __delimiter, FILE *__restrict __stream);


extern __ssize_t  getdelim(char **__restrict __lineptr, size_t *__restrict __n, int __delimiter, FILE *__restrict __stream);









extern __ssize_t  getline(char **__restrict __lineptr, size_t *__restrict __n, FILE *__restrict __stream);










extern int  fputs(__const char *__restrict __s, FILE *__restrict __stream);





extern int  puts(__const char *__s);






extern int  ungetc(int __c, FILE *__stream);






extern size_t  fread(void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream);





extern size_t  fwrite(__const void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __s);
extern size_t  fread_unlocked(void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream);

extern size_t  fwrite_unlocked(__const void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream);









extern int  fseek(FILE *__stream, long int __off, int __whence);




extern long int  ftell(FILE *__stream);




extern void  rewind(FILE *__stream);
extern int  fseeko(FILE *__stream, __off_t __off, int __whence);




extern __off_t  ftello(FILE *__stream);
extern int  fgetpos(FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int  fsetpos(FILE *__stream, __const fpos_t *__pos);
extern void  clearerr(FILE *__stream) __attribute__((__nothrow__)) ;

extern int  feof(FILE *__stream) __attribute__((__nothrow__)) ;

extern int  ferror(FILE *__stream) __attribute__((__nothrow__)) ;




extern void  clearerr_unlocked(FILE *__stream) __attribute__((__nothrow__)) ;
extern int  feof_unlocked(FILE *__stream) __attribute__((__nothrow__)) ;
extern int  ferror_unlocked(FILE *__stream) __attribute__((__nothrow__)) ;








extern void  perror(__const char *__s);
extern int  sys_nerr;
extern __const char  *__const sys_errlist[];
extern int  fileno(FILE *__stream) __attribute__((__nothrow__)) ;




extern int  fileno_unlocked(FILE *__stream) __attribute__((__nothrow__)) ;









extern FILE  *popen(__const char *__command, __const char *__modes);





extern int  pclose(FILE *__stream);





extern char  *ctermid(char *__s) __attribute__((__nothrow__)) ;
extern void  flockfile(FILE *__stream) __attribute__((__nothrow__)) ;



extern int  ftrylockfile(FILE *__stream) __attribute__((__nothrow__)) ;


extern void  funlockfile(FILE *__stream) __attribute__((__nothrow__)) ;
 union wait{

  int  w_status;
   struct __belooga_anonymous_type__997{


    unsigned int  __w_termsig:7;
    unsigned int  __w_coredump:1;
    unsigned int  __w_retcode:8;
    unsigned int  :16;
  } __wait_terminated;







   struct __belooga_anonymous_type__1002{


    unsigned int  __w_stopval:8;
    unsigned int  __w_stopsig:8;
    unsigned int  :16;
  } __wait_stopped;
} ;
typedef  union __belooga_anonymous_type__1006{

  union wait  *__uptr;
  int  *__iptr;
} __WAIT_STATUS __attribute__((__transparent_union__)) ;
typedef  struct __belooga_anonymous_type__1010{

  int  quot;
  int  rem;
} div_t;



typedef  struct __belooga_anonymous_type__1012{

  long int  quot;
  long int  rem;
} ldiv_t;







 __extension__ typedef  struct __belooga_anonymous_type__1016{

  long long int  quot;
  long long int  rem;
} lldiv_t;
extern size_t  __ctype_get_mb_cur_max(void ) __attribute__((__nothrow__)) ;




extern double  atof(__const char *__nptr) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1))) ;


extern int  atoi(__const char *__nptr) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1))) ;


extern long int  atol(__const char *__nptr) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1))) ;






 __extension__ extern long long int  atoll(__const char *__nptr) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1))) ;






extern double  strtod(__const char *__restrict __nptr, char **__restrict __endptr) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;







extern float  strtof(__const char *__restrict __nptr, char **__restrict __endptr) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;


extern long double  strtold(__const char *__restrict __nptr, char **__restrict __endptr) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;







extern long int  strtol(__const char *__restrict __nptr, char **__restrict __endptr, int __base) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;



extern unsigned long int  strtoul(__const char *__restrict __nptr, char **__restrict __endptr, int __base) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;







 __extension__ extern long long int  strtoq(__const char *__restrict __nptr, char **__restrict __endptr, int __base) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;




 __extension__ extern unsigned long long int  strtouq(__const char *__restrict __nptr, char **__restrict __endptr, int __base) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;








 __extension__ extern long long int  strtoll(__const char *__restrict __nptr, char **__restrict __endptr, int __base) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;




 __extension__ extern unsigned long long int  strtoull(__const char *__restrict __nptr, char **__restrict __endptr, int __base) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;
extern char  *l64a(long int __n) __attribute__((__nothrow__)) ;


extern long int  a64l(__const char *__s) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1))) ;
typedef __u_char  u_char;
typedef __u_short  u_short;
typedef __u_int  u_int;
typedef __u_long  u_long;
typedef __quad_t  quad_t;
typedef __u_quad_t  u_quad_t;
typedef __fsid_t  fsid_t;




typedef __loff_t  loff_t;



typedef __ino_t  ino_t;
typedef __dev_t  dev_t;




typedef __gid_t  gid_t;




typedef __mode_t  mode_t;




typedef __nlink_t  nlink_t;




typedef __uid_t  uid_t;
typedef __pid_t  pid_t;





typedef __id_t  id_t;










typedef __daddr_t  daddr_t;
typedef __caddr_t  caddr_t;





typedef __key_t  key_t;
typedef __clock_t  clock_t;
typedef __time_t  time_t;
typedef __clockid_t  clockid_t;
typedef __timer_t  timer_t;
typedef unsigned long int  ulong;
typedef unsigned short int  ushort;
typedef unsigned int  uint;
typedef int  int8_t __attribute__((__mode__ (__QI__))) ;
typedef int  int16_t __attribute__((__mode__ (__HI__))) ;
typedef int  int32_t __attribute__((__mode__ (__SI__))) ;
typedef int  int64_t __attribute__((__mode__ (__DI__))) ;


typedef unsigned int  u_int8_t __attribute__((__mode__ (__QI__))) ;
typedef unsigned int  u_int16_t __attribute__((__mode__ (__HI__))) ;
typedef unsigned int  u_int32_t __attribute__((__mode__ (__SI__))) ;
typedef unsigned int  u_int64_t __attribute__((__mode__ (__DI__))) ;

typedef int  register_t __attribute__((__mode__ (__word__))) ;
typedef int  __sig_atomic_t;




typedef  struct __belooga_anonymous_type__1204{

  unsigned long int  __val[(1024 / (8 * sizeof (unsigned long int )))];
} __sigset_t;
typedef __sigset_t  sigset_t;
 struct timespec{

  __time_t  tv_sec;
  long int  tv_nsec;
} ;
 struct timeval{

  __time_t  tv_sec;
  __suseconds_t  tv_usec;
} ;
typedef __suseconds_t  suseconds_t;





typedef long int  __fd_mask;
typedef  struct __belooga_anonymous_type__1223{







  __fd_mask  __fds_bits[1024 / (8 * (int ) sizeof (__fd_mask ))];
} fd_set;








typedef __fd_mask  fd_mask;
extern int  select(int __nfds, fd_set *__restrict __readfds, fd_set *__restrict __writefds, fd_set *__restrict __exceptfds, struct timeval *__restrict __timeout);
extern int  pselect(int __nfds, fd_set *__restrict __readfds, fd_set *__restrict __writefds, fd_set *__restrict __exceptfds, const struct timespec *__restrict __timeout, const __sigset_t *__restrict __sigmask);
 __extension__ extern unsigned int  gnu_dev_major(unsigned long long int __dev) __attribute__((__nothrow__)) ;


 __extension__ extern unsigned int  gnu_dev_minor(unsigned long long int __dev) __attribute__((__nothrow__)) ;


 __extension__ extern unsigned long long int  gnu_dev_makedev(unsigned int __major, unsigned int __minor) __attribute__((__nothrow__)) ;
typedef __blksize_t  blksize_t;






typedef __blkcnt_t  blkcnt_t;



typedef __fsblkcnt_t  fsblkcnt_t;



typedef __fsfilcnt_t  fsfilcnt_t;
typedef unsigned long int  pthread_t;


typedef  union __belooga_anonymous_type__1289{

  char  __size[56];
  long int  __align;
} pthread_attr_t;



typedef  struct __pthread_internal_list{

  struct __pthread_internal_list  *__prev;
  struct __pthread_internal_list  *__next;
} __pthread_list_t;










typedef  union __belooga_anonymous_type__1297{

   struct __pthread_mutex_s{

    int  __lock;
    unsigned int  __count;
    int  __owner;

    unsigned int  __nusers;



    int  __kind;

    int  __spins;
    __pthread_list_t  __list;
  } __data;









  char  __size[40];
  long int  __align;
} pthread_mutex_t;

typedef  union __belooga_anonymous_type__1305{

  char  __size[4];
  int  __align;
} pthread_mutexattr_t;




typedef  union __belooga_anonymous_type__1308{

   struct __belooga_anonymous_type__1309{

    int  __lock;
    unsigned int  __futex;
 __extension__     unsigned long long int  __total_seq;
 __extension__     unsigned long long int  __wakeup_seq;
 __extension__     unsigned long long int  __woken_seq;
    void  *__mutex;
    unsigned int  __nwaiters;
    unsigned int  __broadcast_seq;
  } __data;
  char  __size[48];
 __extension__   long long int  __align;
} pthread_cond_t;

typedef  union __belooga_anonymous_type__1327{

  char  __size[4];
  int  __align;
} pthread_condattr_t;



typedef unsigned int  pthread_key_t;



typedef int  pthread_once_t;





typedef  union __belooga_anonymous_type__1333{


   struct __belooga_anonymous_type__1334{

    int  __lock;
    unsigned int  __nr_readers;
    unsigned int  __readers_wakeup;
    unsigned int  __writer_wakeup;
    unsigned int  __nr_readers_queued;
    unsigned int  __nr_writers_queued;
    int  __writer;
    int  __shared;
    unsigned long int  __pad1;
    unsigned long int  __pad2;


    unsigned int  __flags;
  } __data;
  char  __size[56];
  long int  __align;
} pthread_rwlock_t;

typedef  union __belooga_anonymous_type__1348{

  char  __size[8];
  long int  __align;
} pthread_rwlockattr_t;





typedef volatile int  pthread_spinlock_t;




typedef  union __belooga_anonymous_type__1354{

  char  __size[32];
  long int  __align;
} pthread_barrier_t;

typedef  union __belooga_anonymous_type__1358{

  char  __size[4];
  int  __align;
} pthread_barrierattr_t;
extern long int  random(void ) __attribute__((__nothrow__)) ;


extern void  srandom(unsigned int __seed) __attribute__((__nothrow__)) ;





extern char  *initstate(unsigned int __seed, char *__statebuf, size_t __statelen) __attribute__((__nothrow__))  __attribute__((__nonnull__ (2))) ;




extern char  *setstate(char *__statebuf) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;







 struct random_data{

  int32_t  *fptr;
  int32_t  *rptr;
  int32_t  *state;
  int  rand_type;
  int  rand_deg;
  int  rand_sep;
  int32_t  *end_ptr;
} ;

extern int  random_r(struct random_data *__restrict __buf, int32_t *__restrict __result) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;


extern int  srandom_r(unsigned int __seed, struct random_data *__buf) __attribute__((__nothrow__))  __attribute__((__nonnull__ (2))) ;


extern int  initstate_r(unsigned int __seed, char *__restrict __statebuf, size_t __statelen, struct random_data *__restrict __buf) __attribute__((__nothrow__))  __attribute__((__nonnull__ (2, 4))) ;




extern int  setstate_r(char *__restrict __statebuf, struct random_data *__restrict __buf) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;








extern int  rand(void ) __attribute__((__nothrow__)) ;

extern void  srand(unsigned int __seed) __attribute__((__nothrow__)) ;




extern int  rand_r(unsigned int *__seed) __attribute__((__nothrow__)) ;







extern double  drand48(void ) __attribute__((__nothrow__)) ;
extern double  erand48(unsigned short int __xsubi[3]) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;


extern long int  lrand48(void ) __attribute__((__nothrow__)) ;
extern long int  nrand48(unsigned short int __xsubi[3]) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;



extern long int  mrand48(void ) __attribute__((__nothrow__)) ;
extern long int  jrand48(unsigned short int __xsubi[3]) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;



extern void  srand48(long int __seedval) __attribute__((__nothrow__)) ;
extern unsigned short int  *seed48(unsigned short int __seed16v[3]) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;

extern void  lcong48(unsigned short int __param[7]) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;





 struct drand48_data{

  unsigned short int  __x[3];
  unsigned short int  __old_x[3];
  unsigned short int  __c;
  unsigned short int  __init;
  unsigned long long int  __a;
} ;


extern int  drand48_r(struct drand48_data *__restrict __buffer, double *__restrict __result) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;

extern int  erand48_r(unsigned short int __xsubi[3], struct drand48_data *__restrict __buffer, double *__restrict __result) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;




extern int  lrand48_r(struct drand48_data *__restrict __buffer, long int *__restrict __result) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;


extern int  nrand48_r(unsigned short int __xsubi[3], struct drand48_data *__restrict __buffer, long int *__restrict __result) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;





extern int  mrand48_r(struct drand48_data *__restrict __buffer, long int *__restrict __result) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;


extern int  jrand48_r(unsigned short int __xsubi[3], struct drand48_data *__restrict __buffer, long int *__restrict __result) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;





extern int  srand48_r(long int __seedval, struct drand48_data *__buffer) __attribute__((__nothrow__))  __attribute__((__nonnull__ (2))) ;


extern int  seed48_r(unsigned short int __seed16v[3], struct drand48_data *__buffer) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;


extern int  lcong48_r(unsigned short int __param[7], struct drand48_data *__buffer) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;
extern void  *malloc(size_t __size) __attribute__((__nothrow__))  __attribute__((__malloc__)) ;

extern void  *calloc(size_t __nmemb, size_t __size) __attribute__((__nothrow__))  __attribute__((__malloc__)) ;
extern void  *realloc(void *__ptr, size_t __size) __attribute__((__nothrow__))  __attribute__((__warn_unused_result__)) ;


extern void  free(void *__ptr) __attribute__((__nothrow__)) ;




extern void  cfree(void *__ptr) __attribute__((__nothrow__)) ;
extern void  *alloca(size_t __size) __attribute__((__nothrow__)) ;
extern void  *valloc(size_t __size) __attribute__((__nothrow__))  __attribute__((__malloc__)) ;




extern int  posix_memalign(void **__memptr, size_t __alignment, size_t __size) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;





extern void  abort(void ) __attribute__((__nothrow__))  __attribute__((__noreturn__)) ;



extern int  atexit(void (*__func)(void )) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;
extern int  on_exit(void (*__func)(int __status, void *__arg), void *__arg) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;







extern void  exit(int __status) __attribute__((__nothrow__))  __attribute__((__noreturn__)) ;
extern void  _Exit(int __status) __attribute__((__nothrow__))  __attribute__((__noreturn__)) ;






extern char  *getenv(__const char *__name) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;




extern char  *__secure_getenv(__const char *__name) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;






extern int  putenv(char *__string) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;





extern int  setenv(__const char *__name, __const char *__value, int __replace) __attribute__((__nothrow__))  __attribute__((__nonnull__ (2))) ;



extern int  unsetenv(__const char *__name) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;






extern int  clearenv(void ) __attribute__((__nothrow__)) ;









extern char  *mktemp(char *__template) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;
extern int  mkstemp(char *__template) __attribute__((__nonnull__ (1))) ;
extern int  mkstemps(char *__template, int __suffixlen) __attribute__((__nonnull__ (1))) ;
extern char  *mkdtemp(char *__template) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;
extern int  system(__const char *__command);
extern char  *realpath(__const char *__restrict __name, char *__restrict __resolved) __attribute__((__nothrow__)) ;







typedef int  (*__compar_fn_t)(__const void *, __const void *);
extern void  *bsearch(__const void *__key, __const void *__base, size_t __nmemb, size_t __size, __compar_fn_t __compar) __attribute__((__nonnull__ (1, 2, 5))) ;





extern void  qsort(void *__base, size_t __nmemb, size_t __size, __compar_fn_t __compar) __attribute__((__nonnull__ (1, 4))) ;









extern int  abs(int __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;
extern long int  labs(long int __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;



 __extension__ extern long long int  llabs(long long int __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;








extern div_t  div(int __numer, int __denom) __attribute__((__nothrow__))  __attribute__((__const__)) ;

extern ldiv_t  ldiv(long int __numer, long int __denom) __attribute__((__nothrow__))  __attribute__((__const__)) ;





 __extension__ extern lldiv_t  lldiv(long long int __numer, long long int __denom) __attribute__((__nothrow__))  __attribute__((__const__)) ;
extern char  *ecvt(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) __attribute__((__nothrow__))  __attribute__((__nonnull__ (3, 4))) ;





extern char  *fcvt(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) __attribute__((__nothrow__))  __attribute__((__nonnull__ (3, 4))) ;





extern char  *gcvt(double __value, int __ndigit, char *__buf) __attribute__((__nothrow__))  __attribute__((__nonnull__ (3))) ;





extern char  *qecvt(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) __attribute__((__nothrow__))  __attribute__((__nonnull__ (3, 4))) ;


extern char  *qfcvt(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign) __attribute__((__nothrow__))  __attribute__((__nonnull__ (3, 4))) ;


extern char  *qgcvt(long double __value, int __ndigit, char *__buf) __attribute__((__nothrow__))  __attribute__((__nonnull__ (3))) ;





extern int  ecvt_r(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf, size_t __len) __attribute__((__nothrow__))  __attribute__((__nonnull__ (3, 4, 5))) ;


extern int  fcvt_r(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf, size_t __len) __attribute__((__nothrow__))  __attribute__((__nonnull__ (3, 4, 5))) ;



extern int  qecvt_r(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf, size_t __len) __attribute__((__nothrow__))  __attribute__((__nonnull__ (3, 4, 5))) ;



extern int  qfcvt_r(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf, size_t __len) __attribute__((__nothrow__))  __attribute__((__nonnull__ (3, 4, 5))) ;










extern int  mblen(__const char *__s, size_t __n) __attribute__((__nothrow__)) ;


extern int  mbtowc(wchar_t *__restrict __pwc, __const char *__restrict __s, size_t __n) __attribute__((__nothrow__)) ;



extern int  wctomb(char *__s, wchar_t __wchar) __attribute__((__nothrow__)) ;



extern size_t  mbstowcs(wchar_t *__restrict __pwcs, __const char *__restrict __s, size_t __n) __attribute__((__nothrow__)) ;


extern size_t  wcstombs(char *__restrict __s, __const wchar_t *__restrict __pwcs, size_t __n) __attribute__((__nothrow__)) ;










extern int  rpmatch(__const char *__response) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;










extern int  getsubopt(char **__restrict __optionp, char *__const *__restrict __tokens, char **__restrict __valuep) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2, 3))) ;
extern int  getloadavg(double __loadavg[], int __nelem) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;
typedef float  float_t;
typedef double  double_t;
extern double  acos(double __x) __attribute__((__nothrow__)) ;extern double  __acos(double __x) __attribute__((__nothrow__)) ;

extern double  asin(double __x) __attribute__((__nothrow__)) ;extern double  __asin(double __x) __attribute__((__nothrow__)) ;

extern double  atan(double __x) __attribute__((__nothrow__)) ;extern double  __atan(double __x) __attribute__((__nothrow__)) ;

extern double  atan2(double __y, double __x) __attribute__((__nothrow__)) ;extern double  __atan2(double __y, double __x) __attribute__((__nothrow__)) ;


extern double  cos(double __x) __attribute__((__nothrow__)) ;extern double  __cos(double __x) __attribute__((__nothrow__)) ;

extern double  sin(double __x) __attribute__((__nothrow__)) ;extern double  __sin(double __x) __attribute__((__nothrow__)) ;

extern double  tan(double __x) __attribute__((__nothrow__)) ;extern double  __tan(double __x) __attribute__((__nothrow__)) ;




extern double  cosh(double __x) __attribute__((__nothrow__)) ;extern double  __cosh(double __x) __attribute__((__nothrow__)) ;

extern double  sinh(double __x) __attribute__((__nothrow__)) ;extern double  __sinh(double __x) __attribute__((__nothrow__)) ;

extern double  tanh(double __x) __attribute__((__nothrow__)) ;extern double  __tanh(double __x) __attribute__((__nothrow__)) ;
extern double  acosh(double __x) __attribute__((__nothrow__)) ;extern double  __acosh(double __x) __attribute__((__nothrow__)) ;

extern double  asinh(double __x) __attribute__((__nothrow__)) ;extern double  __asinh(double __x) __attribute__((__nothrow__)) ;

extern double  atanh(double __x) __attribute__((__nothrow__)) ;extern double  __atanh(double __x) __attribute__((__nothrow__)) ;







extern double  exp(double __x) __attribute__((__nothrow__)) ;extern double  __exp(double __x) __attribute__((__nothrow__)) ;


extern double  frexp(double __x, int *__exponent) __attribute__((__nothrow__)) ;extern double  __frexp(double __x, int *__exponent) __attribute__((__nothrow__)) ;


extern double  ldexp(double __x, int __exponent) __attribute__((__nothrow__)) ;extern double  __ldexp(double __x, int __exponent) __attribute__((__nothrow__)) ;


extern double  log(double __x) __attribute__((__nothrow__)) ;extern double  __log(double __x) __attribute__((__nothrow__)) ;


extern double  log10(double __x) __attribute__((__nothrow__)) ;extern double  __log10(double __x) __attribute__((__nothrow__)) ;


extern double  modf(double __x, double *__iptr) __attribute__((__nothrow__)) ;extern double  __modf(double __x, double *__iptr) __attribute__((__nothrow__)) ;
extern double  expm1(double __x) __attribute__((__nothrow__)) ;extern double  __expm1(double __x) __attribute__((__nothrow__)) ;


extern double  log1p(double __x) __attribute__((__nothrow__)) ;extern double  __log1p(double __x) __attribute__((__nothrow__)) ;


extern double  logb(double __x) __attribute__((__nothrow__)) ;extern double  __logb(double __x) __attribute__((__nothrow__)) ;






extern double  exp2(double __x) __attribute__((__nothrow__)) ;extern double  __exp2(double __x) __attribute__((__nothrow__)) ;


extern double  log2(double __x) __attribute__((__nothrow__)) ;extern double  __log2(double __x) __attribute__((__nothrow__)) ;








extern double  pow(double __x, double __y) __attribute__((__nothrow__)) ;extern double  __pow(double __x, double __y) __attribute__((__nothrow__)) ;


extern double  sqrt(double __x) __attribute__((__nothrow__)) ;extern double  __sqrt(double __x) __attribute__((__nothrow__)) ;





extern double  hypot(double __x, double __y) __attribute__((__nothrow__)) ;extern double  __hypot(double __x, double __y) __attribute__((__nothrow__)) ;






extern double  cbrt(double __x) __attribute__((__nothrow__)) ;extern double  __cbrt(double __x) __attribute__((__nothrow__)) ;








extern double  ceil(double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern double  __ceil(double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern double  fabs(double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern double  __fabs(double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern double  floor(double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern double  __floor(double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern double  fmod(double __x, double __y) __attribute__((__nothrow__)) ;extern double  __fmod(double __x, double __y) __attribute__((__nothrow__)) ;




extern int  __isinf(double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern int  __finite(double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;





extern int  isinf(double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern int  finite(double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern double  drem(double __x, double __y) __attribute__((__nothrow__)) ;extern double  __drem(double __x, double __y) __attribute__((__nothrow__)) ;



extern double  significand(double __x) __attribute__((__nothrow__)) ;extern double  __significand(double __x) __attribute__((__nothrow__)) ;





extern double  copysign(double __x, double __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern double  __copysign(double __x, double __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;






extern double  nan(__const char *__tagb) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern double  __nan(__const char *__tagb) __attribute__((__nothrow__))  __attribute__((__const__)) ;





extern int  __isnan(double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;



extern int  isnan(double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern double  j0(double ) __attribute__((__nothrow__)) ;extern double  __j0(double ) __attribute__((__nothrow__)) ;
extern double  j1(double ) __attribute__((__nothrow__)) ;extern double  __j1(double ) __attribute__((__nothrow__)) ;
extern double  jn(int , double ) __attribute__((__nothrow__)) ;extern double  __jn(int , double ) __attribute__((__nothrow__)) ;
extern double  y0(double ) __attribute__((__nothrow__)) ;extern double  __y0(double ) __attribute__((__nothrow__)) ;
extern double  y1(double ) __attribute__((__nothrow__)) ;extern double  __y1(double ) __attribute__((__nothrow__)) ;
extern double  yn(int , double ) __attribute__((__nothrow__)) ;extern double  __yn(int , double ) __attribute__((__nothrow__)) ;






extern double  erf(double ) __attribute__((__nothrow__)) ;extern double  __erf(double ) __attribute__((__nothrow__)) ;
extern double  erfc(double ) __attribute__((__nothrow__)) ;extern double  __erfc(double ) __attribute__((__nothrow__)) ;
extern double  lgamma(double ) __attribute__((__nothrow__)) ;extern double  __lgamma(double ) __attribute__((__nothrow__)) ;






extern double  tgamma(double ) __attribute__((__nothrow__)) ;extern double  __tgamma(double ) __attribute__((__nothrow__)) ;





extern double  gamma(double ) __attribute__((__nothrow__)) ;extern double  __gamma(double ) __attribute__((__nothrow__)) ;






extern double  lgamma_r(double , int *__signgamp) __attribute__((__nothrow__)) ;extern double  __lgamma_r(double , int *__signgamp) __attribute__((__nothrow__)) ;







extern double  rint(double __x) __attribute__((__nothrow__)) ;extern double  __rint(double __x) __attribute__((__nothrow__)) ;


extern double  nextafter(double __x, double __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern double  __nextafter(double __x, double __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;

extern double  nexttoward(double __x, long double __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern double  __nexttoward(double __x, long double __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;



extern double  remainder(double __x, double __y) __attribute__((__nothrow__)) ;extern double  __remainder(double __x, double __y) __attribute__((__nothrow__)) ;



extern double  scalbn(double __x, int __n) __attribute__((__nothrow__)) ;extern double  __scalbn(double __x, int __n) __attribute__((__nothrow__)) ;



extern int  ilogb(double __x) __attribute__((__nothrow__)) ;extern int  __ilogb(double __x) __attribute__((__nothrow__)) ;




extern double  scalbln(double __x, long int __n) __attribute__((__nothrow__)) ;extern double  __scalbln(double __x, long int __n) __attribute__((__nothrow__)) ;



extern double  nearbyint(double __x) __attribute__((__nothrow__)) ;extern double  __nearbyint(double __x) __attribute__((__nothrow__)) ;



extern double  round(double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern double  __round(double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;



extern double  trunc(double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern double  __trunc(double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;




extern double  remquo(double __x, double __y, int *__quo) __attribute__((__nothrow__)) ;extern double  __remquo(double __x, double __y, int *__quo) __attribute__((__nothrow__)) ;






extern long int  lrint(double __x) __attribute__((__nothrow__)) ;extern long int  __lrint(double __x) __attribute__((__nothrow__)) ;
extern long long int  llrint(double __x) __attribute__((__nothrow__)) ;extern long long int  __llrint(double __x) __attribute__((__nothrow__)) ;



extern long int  lround(double __x) __attribute__((__nothrow__)) ;extern long int  __lround(double __x) __attribute__((__nothrow__)) ;
extern long long int  llround(double __x) __attribute__((__nothrow__)) ;extern long long int  __llround(double __x) __attribute__((__nothrow__)) ;



extern double  fdim(double __x, double __y) __attribute__((__nothrow__)) ;extern double  __fdim(double __x, double __y) __attribute__((__nothrow__)) ;


extern double  fmax(double __x, double __y) __attribute__((__nothrow__)) ;extern double  __fmax(double __x, double __y) __attribute__((__nothrow__)) ;


extern double  fmin(double __x, double __y) __attribute__((__nothrow__)) ;extern double  __fmin(double __x, double __y) __attribute__((__nothrow__)) ;



extern int  __fpclassify(double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;



extern int  __signbit(double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;




extern double  fma(double __x, double __y, double __z) __attribute__((__nothrow__)) ;extern double  __fma(double __x, double __y, double __z) __attribute__((__nothrow__)) ;








extern double  scalb(double __x, double __n) __attribute__((__nothrow__)) ;extern double  __scalb(double __x, double __n) __attribute__((__nothrow__)) ;
extern float  acosf(float __x) __attribute__((__nothrow__)) ;extern float  __acosf(float __x) __attribute__((__nothrow__)) ;

extern float  asinf(float __x) __attribute__((__nothrow__)) ;extern float  __asinf(float __x) __attribute__((__nothrow__)) ;

extern float  atanf(float __x) __attribute__((__nothrow__)) ;extern float  __atanf(float __x) __attribute__((__nothrow__)) ;

extern float  atan2f(float __y, float __x) __attribute__((__nothrow__)) ;extern float  __atan2f(float __y, float __x) __attribute__((__nothrow__)) ;


extern float  cosf(float __x) __attribute__((__nothrow__)) ;extern float  __cosf(float __x) __attribute__((__nothrow__)) ;

extern float  sinf(float __x) __attribute__((__nothrow__)) ;extern float  __sinf(float __x) __attribute__((__nothrow__)) ;

extern float  tanf(float __x) __attribute__((__nothrow__)) ;extern float  __tanf(float __x) __attribute__((__nothrow__)) ;




extern float  coshf(float __x) __attribute__((__nothrow__)) ;extern float  __coshf(float __x) __attribute__((__nothrow__)) ;

extern float  sinhf(float __x) __attribute__((__nothrow__)) ;extern float  __sinhf(float __x) __attribute__((__nothrow__)) ;

extern float  tanhf(float __x) __attribute__((__nothrow__)) ;extern float  __tanhf(float __x) __attribute__((__nothrow__)) ;
extern float  acoshf(float __x) __attribute__((__nothrow__)) ;extern float  __acoshf(float __x) __attribute__((__nothrow__)) ;

extern float  asinhf(float __x) __attribute__((__nothrow__)) ;extern float  __asinhf(float __x) __attribute__((__nothrow__)) ;

extern float  atanhf(float __x) __attribute__((__nothrow__)) ;extern float  __atanhf(float __x) __attribute__((__nothrow__)) ;







extern float  expf(float __x) __attribute__((__nothrow__)) ;extern float  __expf(float __x) __attribute__((__nothrow__)) ;


extern float  frexpf(float __x, int *__exponent) __attribute__((__nothrow__)) ;extern float  __frexpf(float __x, int *__exponent) __attribute__((__nothrow__)) ;


extern float  ldexpf(float __x, int __exponent) __attribute__((__nothrow__)) ;extern float  __ldexpf(float __x, int __exponent) __attribute__((__nothrow__)) ;


extern float  logf(float __x) __attribute__((__nothrow__)) ;extern float  __logf(float __x) __attribute__((__nothrow__)) ;


extern float  log10f(float __x) __attribute__((__nothrow__)) ;extern float  __log10f(float __x) __attribute__((__nothrow__)) ;


extern float  modff(float __x, float *__iptr) __attribute__((__nothrow__)) ;extern float  __modff(float __x, float *__iptr) __attribute__((__nothrow__)) ;
extern float  expm1f(float __x) __attribute__((__nothrow__)) ;extern float  __expm1f(float __x) __attribute__((__nothrow__)) ;


extern float  log1pf(float __x) __attribute__((__nothrow__)) ;extern float  __log1pf(float __x) __attribute__((__nothrow__)) ;


extern float  logbf(float __x) __attribute__((__nothrow__)) ;extern float  __logbf(float __x) __attribute__((__nothrow__)) ;






extern float  exp2f(float __x) __attribute__((__nothrow__)) ;extern float  __exp2f(float __x) __attribute__((__nothrow__)) ;


extern float  log2f(float __x) __attribute__((__nothrow__)) ;extern float  __log2f(float __x) __attribute__((__nothrow__)) ;








extern float  powf(float __x, float __y) __attribute__((__nothrow__)) ;extern float  __powf(float __x, float __y) __attribute__((__nothrow__)) ;


extern float  sqrtf(float __x) __attribute__((__nothrow__)) ;extern float  __sqrtf(float __x) __attribute__((__nothrow__)) ;





extern float  hypotf(float __x, float __y) __attribute__((__nothrow__)) ;extern float  __hypotf(float __x, float __y) __attribute__((__nothrow__)) ;






extern float  cbrtf(float __x) __attribute__((__nothrow__)) ;extern float  __cbrtf(float __x) __attribute__((__nothrow__)) ;








extern float  ceilf(float __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern float  __ceilf(float __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern float  fabsf(float __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern float  __fabsf(float __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern float  floorf(float __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern float  __floorf(float __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern float  fmodf(float __x, float __y) __attribute__((__nothrow__)) ;extern float  __fmodf(float __x, float __y) __attribute__((__nothrow__)) ;




extern int  __isinff(float __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern int  __finitef(float __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;





extern int  isinff(float __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern int  finitef(float __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern float  dremf(float __x, float __y) __attribute__((__nothrow__)) ;extern float  __dremf(float __x, float __y) __attribute__((__nothrow__)) ;



extern float  significandf(float __x) __attribute__((__nothrow__)) ;extern float  __significandf(float __x) __attribute__((__nothrow__)) ;





extern float  copysignf(float __x, float __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern float  __copysignf(float __x, float __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;






extern float  nanf(__const char *__tagb) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern float  __nanf(__const char *__tagb) __attribute__((__nothrow__))  __attribute__((__const__)) ;





extern int  __isnanf(float __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;



extern int  isnanf(float __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern float  j0f(float ) __attribute__((__nothrow__)) ;extern float  __j0f(float ) __attribute__((__nothrow__)) ;
extern float  j1f(float ) __attribute__((__nothrow__)) ;extern float  __j1f(float ) __attribute__((__nothrow__)) ;
extern float  jnf(int , float ) __attribute__((__nothrow__)) ;extern float  __jnf(int , float ) __attribute__((__nothrow__)) ;
extern float  y0f(float ) __attribute__((__nothrow__)) ;extern float  __y0f(float ) __attribute__((__nothrow__)) ;
extern float  y1f(float ) __attribute__((__nothrow__)) ;extern float  __y1f(float ) __attribute__((__nothrow__)) ;
extern float  ynf(int , float ) __attribute__((__nothrow__)) ;extern float  __ynf(int , float ) __attribute__((__nothrow__)) ;






extern float  erff(float ) __attribute__((__nothrow__)) ;extern float  __erff(float ) __attribute__((__nothrow__)) ;
extern float  erfcf(float ) __attribute__((__nothrow__)) ;extern float  __erfcf(float ) __attribute__((__nothrow__)) ;
extern float  lgammaf(float ) __attribute__((__nothrow__)) ;extern float  __lgammaf(float ) __attribute__((__nothrow__)) ;






extern float  tgammaf(float ) __attribute__((__nothrow__)) ;extern float  __tgammaf(float ) __attribute__((__nothrow__)) ;





extern float  gammaf(float ) __attribute__((__nothrow__)) ;extern float  __gammaf(float ) __attribute__((__nothrow__)) ;






extern float  lgammaf_r(float , int *__signgamp) __attribute__((__nothrow__)) ;extern float  __lgammaf_r(float , int *__signgamp) __attribute__((__nothrow__)) ;







extern float  rintf(float __x) __attribute__((__nothrow__)) ;extern float  __rintf(float __x) __attribute__((__nothrow__)) ;


extern float  nextafterf(float __x, float __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern float  __nextafterf(float __x, float __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;

extern float  nexttowardf(float __x, long double __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern float  __nexttowardf(float __x, long double __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;



extern float  remainderf(float __x, float __y) __attribute__((__nothrow__)) ;extern float  __remainderf(float __x, float __y) __attribute__((__nothrow__)) ;



extern float  scalbnf(float __x, int __n) __attribute__((__nothrow__)) ;extern float  __scalbnf(float __x, int __n) __attribute__((__nothrow__)) ;



extern int  ilogbf(float __x) __attribute__((__nothrow__)) ;extern int  __ilogbf(float __x) __attribute__((__nothrow__)) ;




extern float  scalblnf(float __x, long int __n) __attribute__((__nothrow__)) ;extern float  __scalblnf(float __x, long int __n) __attribute__((__nothrow__)) ;



extern float  nearbyintf(float __x) __attribute__((__nothrow__)) ;extern float  __nearbyintf(float __x) __attribute__((__nothrow__)) ;



extern float  roundf(float __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern float  __roundf(float __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;



extern float  truncf(float __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern float  __truncf(float __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;




extern float  remquof(float __x, float __y, int *__quo) __attribute__((__nothrow__)) ;extern float  __remquof(float __x, float __y, int *__quo) __attribute__((__nothrow__)) ;






extern long int  lrintf(float __x) __attribute__((__nothrow__)) ;extern long int  __lrintf(float __x) __attribute__((__nothrow__)) ;
extern long long int  llrintf(float __x) __attribute__((__nothrow__)) ;extern long long int  __llrintf(float __x) __attribute__((__nothrow__)) ;



extern long int  lroundf(float __x) __attribute__((__nothrow__)) ;extern long int  __lroundf(float __x) __attribute__((__nothrow__)) ;
extern long long int  llroundf(float __x) __attribute__((__nothrow__)) ;extern long long int  __llroundf(float __x) __attribute__((__nothrow__)) ;



extern float  fdimf(float __x, float __y) __attribute__((__nothrow__)) ;extern float  __fdimf(float __x, float __y) __attribute__((__nothrow__)) ;


extern float  fmaxf(float __x, float __y) __attribute__((__nothrow__)) ;extern float  __fmaxf(float __x, float __y) __attribute__((__nothrow__)) ;


extern float  fminf(float __x, float __y) __attribute__((__nothrow__)) ;extern float  __fminf(float __x, float __y) __attribute__((__nothrow__)) ;



extern int  __fpclassifyf(float __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;



extern int  __signbitf(float __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;




extern float  fmaf(float __x, float __y, float __z) __attribute__((__nothrow__)) ;extern float  __fmaf(float __x, float __y, float __z) __attribute__((__nothrow__)) ;








extern float  scalbf(float __x, float __n) __attribute__((__nothrow__)) ;extern float  __scalbf(float __x, float __n) __attribute__((__nothrow__)) ;
extern long double  acosl(long double __x) __attribute__((__nothrow__)) ;extern long double  __acosl(long double __x) __attribute__((__nothrow__)) ;

extern long double  asinl(long double __x) __attribute__((__nothrow__)) ;extern long double  __asinl(long double __x) __attribute__((__nothrow__)) ;

extern long double  atanl(long double __x) __attribute__((__nothrow__)) ;extern long double  __atanl(long double __x) __attribute__((__nothrow__)) ;

extern long double  atan2l(long double __y, long double __x) __attribute__((__nothrow__)) ;extern long double  __atan2l(long double __y, long double __x) __attribute__((__nothrow__)) ;


extern long double  cosl(long double __x) __attribute__((__nothrow__)) ;extern long double  __cosl(long double __x) __attribute__((__nothrow__)) ;

extern long double  sinl(long double __x) __attribute__((__nothrow__)) ;extern long double  __sinl(long double __x) __attribute__((__nothrow__)) ;

extern long double  tanl(long double __x) __attribute__((__nothrow__)) ;extern long double  __tanl(long double __x) __attribute__((__nothrow__)) ;




extern long double  coshl(long double __x) __attribute__((__nothrow__)) ;extern long double  __coshl(long double __x) __attribute__((__nothrow__)) ;

extern long double  sinhl(long double __x) __attribute__((__nothrow__)) ;extern long double  __sinhl(long double __x) __attribute__((__nothrow__)) ;

extern long double  tanhl(long double __x) __attribute__((__nothrow__)) ;extern long double  __tanhl(long double __x) __attribute__((__nothrow__)) ;
extern long double  acoshl(long double __x) __attribute__((__nothrow__)) ;extern long double  __acoshl(long double __x) __attribute__((__nothrow__)) ;

extern long double  asinhl(long double __x) __attribute__((__nothrow__)) ;extern long double  __asinhl(long double __x) __attribute__((__nothrow__)) ;

extern long double  atanhl(long double __x) __attribute__((__nothrow__)) ;extern long double  __atanhl(long double __x) __attribute__((__nothrow__)) ;







extern long double  expl(long double __x) __attribute__((__nothrow__)) ;extern long double  __expl(long double __x) __attribute__((__nothrow__)) ;


extern long double  frexpl(long double __x, int *__exponent) __attribute__((__nothrow__)) ;extern long double  __frexpl(long double __x, int *__exponent) __attribute__((__nothrow__)) ;


extern long double  ldexpl(long double __x, int __exponent) __attribute__((__nothrow__)) ;extern long double  __ldexpl(long double __x, int __exponent) __attribute__((__nothrow__)) ;


extern long double  logl(long double __x) __attribute__((__nothrow__)) ;extern long double  __logl(long double __x) __attribute__((__nothrow__)) ;


extern long double  log10l(long double __x) __attribute__((__nothrow__)) ;extern long double  __log10l(long double __x) __attribute__((__nothrow__)) ;


extern long double  modfl(long double __x, long double *__iptr) __attribute__((__nothrow__)) ;extern long double  __modfl(long double __x, long double *__iptr) __attribute__((__nothrow__)) ;
extern long double  expm1l(long double __x) __attribute__((__nothrow__)) ;extern long double  __expm1l(long double __x) __attribute__((__nothrow__)) ;


extern long double  log1pl(long double __x) __attribute__((__nothrow__)) ;extern long double  __log1pl(long double __x) __attribute__((__nothrow__)) ;


extern long double  logbl(long double __x) __attribute__((__nothrow__)) ;extern long double  __logbl(long double __x) __attribute__((__nothrow__)) ;






extern long double  exp2l(long double __x) __attribute__((__nothrow__)) ;extern long double  __exp2l(long double __x) __attribute__((__nothrow__)) ;


extern long double  log2l(long double __x) __attribute__((__nothrow__)) ;extern long double  __log2l(long double __x) __attribute__((__nothrow__)) ;








extern long double  powl(long double __x, long double __y) __attribute__((__nothrow__)) ;extern long double  __powl(long double __x, long double __y) __attribute__((__nothrow__)) ;


extern long double  sqrtl(long double __x) __attribute__((__nothrow__)) ;extern long double  __sqrtl(long double __x) __attribute__((__nothrow__)) ;





extern long double  hypotl(long double __x, long double __y) __attribute__((__nothrow__)) ;extern long double  __hypotl(long double __x, long double __y) __attribute__((__nothrow__)) ;






extern long double  cbrtl(long double __x) __attribute__((__nothrow__)) ;extern long double  __cbrtl(long double __x) __attribute__((__nothrow__)) ;








extern long double  ceill(long double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern long double  __ceill(long double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern long double  fabsl(long double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern long double  __fabsl(long double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern long double  floorl(long double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern long double  __floorl(long double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern long double  fmodl(long double __x, long double __y) __attribute__((__nothrow__)) ;extern long double  __fmodl(long double __x, long double __y) __attribute__((__nothrow__)) ;




extern int  __isinfl(long double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern int  __finitel(long double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;





extern int  isinfl(long double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern int  finitel(long double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern long double  dreml(long double __x, long double __y) __attribute__((__nothrow__)) ;extern long double  __dreml(long double __x, long double __y) __attribute__((__nothrow__)) ;



extern long double  significandl(long double __x) __attribute__((__nothrow__)) ;extern long double  __significandl(long double __x) __attribute__((__nothrow__)) ;





extern long double  copysignl(long double __x, long double __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern long double  __copysignl(long double __x, long double __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;






extern long double  nanl(__const char *__tagb) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern long double  __nanl(__const char *__tagb) __attribute__((__nothrow__))  __attribute__((__const__)) ;





extern int  __isnanl(long double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;



extern int  isnanl(long double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;


extern long double  j0l(long double ) __attribute__((__nothrow__)) ;extern long double  __j0l(long double ) __attribute__((__nothrow__)) ;
extern long double  j1l(long double ) __attribute__((__nothrow__)) ;extern long double  __j1l(long double ) __attribute__((__nothrow__)) ;
extern long double  jnl(int , long double ) __attribute__((__nothrow__)) ;extern long double  __jnl(int , long double ) __attribute__((__nothrow__)) ;
extern long double  y0l(long double ) __attribute__((__nothrow__)) ;extern long double  __y0l(long double ) __attribute__((__nothrow__)) ;
extern long double  y1l(long double ) __attribute__((__nothrow__)) ;extern long double  __y1l(long double ) __attribute__((__nothrow__)) ;
extern long double  ynl(int , long double ) __attribute__((__nothrow__)) ;extern long double  __ynl(int , long double ) __attribute__((__nothrow__)) ;






extern long double  erfl(long double ) __attribute__((__nothrow__)) ;extern long double  __erfl(long double ) __attribute__((__nothrow__)) ;
extern long double  erfcl(long double ) __attribute__((__nothrow__)) ;extern long double  __erfcl(long double ) __attribute__((__nothrow__)) ;
extern long double  lgammal(long double ) __attribute__((__nothrow__)) ;extern long double  __lgammal(long double ) __attribute__((__nothrow__)) ;






extern long double  tgammal(long double ) __attribute__((__nothrow__)) ;extern long double  __tgammal(long double ) __attribute__((__nothrow__)) ;





extern long double  gammal(long double ) __attribute__((__nothrow__)) ;extern long double  __gammal(long double ) __attribute__((__nothrow__)) ;






extern long double  lgammal_r(long double , int *__signgamp) __attribute__((__nothrow__)) ;extern long double  __lgammal_r(long double , int *__signgamp) __attribute__((__nothrow__)) ;







extern long double  rintl(long double __x) __attribute__((__nothrow__)) ;extern long double  __rintl(long double __x) __attribute__((__nothrow__)) ;


extern long double  nextafterl(long double __x, long double __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern long double  __nextafterl(long double __x, long double __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;

extern long double  nexttowardl(long double __x, long double __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern long double  __nexttowardl(long double __x, long double __y) __attribute__((__nothrow__))  __attribute__((__const__)) ;



extern long double  remainderl(long double __x, long double __y) __attribute__((__nothrow__)) ;extern long double  __remainderl(long double __x, long double __y) __attribute__((__nothrow__)) ;



extern long double  scalbnl(long double __x, int __n) __attribute__((__nothrow__)) ;extern long double  __scalbnl(long double __x, int __n) __attribute__((__nothrow__)) ;



extern int  ilogbl(long double __x) __attribute__((__nothrow__)) ;extern int  __ilogbl(long double __x) __attribute__((__nothrow__)) ;




extern long double  scalblnl(long double __x, long int __n) __attribute__((__nothrow__)) ;extern long double  __scalblnl(long double __x, long int __n) __attribute__((__nothrow__)) ;



extern long double  nearbyintl(long double __x) __attribute__((__nothrow__)) ;extern long double  __nearbyintl(long double __x) __attribute__((__nothrow__)) ;



extern long double  roundl(long double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern long double  __roundl(long double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;



extern long double  truncl(long double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;extern long double  __truncl(long double __x) __attribute__((__nothrow__))  __attribute__((__const__)) ;




extern long double  remquol(long double __x, long double __y, int *__quo) __attribute__((__nothrow__)) ;extern long double  __remquol(long double __x, long double __y, int *__quo) __attribute__((__nothrow__)) ;






extern long int  lrintl(long double __x) __attribute__((__nothrow__)) ;extern long int  __lrintl(long double __x) __attribute__((__nothrow__)) ;
extern long long int  llrintl(long double __x) __attribute__((__nothrow__)) ;extern long long int  __llrintl(long double __x) __attribute__((__nothrow__)) ;



extern long int  lroundl(long double __x) __attribute__((__nothrow__)) ;extern long int  __lroundl(long double __x) __attribute__((__nothrow__)) ;
extern long long int  llroundl(long double __x) __attribute__((__nothrow__)) ;extern long long int  __llroundl(long double __x) __attribute__((__nothrow__)) ;



extern long double  fdiml(long double __x, long double __y) __attribute__((__nothrow__)) ;extern long double  __fdiml(long double __x, long double __y) __attribute__((__nothrow__)) ;


extern long double  fmaxl(long double __x, long double __y) __attribute__((__nothrow__)) ;extern long double  __fmaxl(long double __x, long double __y) __attribute__((__nothrow__)) ;


extern long double  fminl(long double __x, long double __y) __attribute__((__nothrow__)) ;extern long double  __fminl(long double __x, long double __y) __attribute__((__nothrow__)) ;



extern int  __fpclassifyl(long double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;



extern int  __signbitl(long double __value) __attribute__((__nothrow__))  __attribute__((__const__)) ;




extern long double  fmal(long double __x, long double __y, long double __z) __attribute__((__nothrow__)) ;extern long double  __fmal(long double __x, long double __y, long double __z) __attribute__((__nothrow__)) ;








extern long double  scalbl(long double __x, long double __n) __attribute__((__nothrow__)) ;extern long double  __scalbl(long double __x, long double __n) __attribute__((__nothrow__)) ;
extern int  signgam;
 enum __belooga_anonymous_type__2726{

FP_NAN, FP_INFINITE, FP_ZERO, FP_SUBNORMAL, FP_NORMAL}
;
typedef  enum __belooga_anonymous_type__2727{

_IEEE_ =  -1, _SVID_, _XOPEN_, _POSIX_, _ISOC_}
_LIB_VERSION_TYPE;








extern _LIB_VERSION_TYPE  _LIB_VERSION;
 struct exception{


  int  type;
  char  *name;
  double  arg1;
  double  arg2;
  double  retval;
} ;




extern int  matherr(struct exception *__exc);
extern void  *memcpy(void *__restrict __dest, __const void *__restrict __src, size_t __n) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;




extern void  *memmove(void *__dest, __const void *__src, size_t __n) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;







extern void  *memccpy(void *__restrict __dest, __const void *__restrict __src, int __c, size_t __n) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;







extern void  *memset(void *__s, int __c, size_t __n) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;


extern int  memcmp(__const void *__s1, __const void *__s2, size_t __n) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1, 2))) ;
extern void  *memchr(__const void *__s, int __c, size_t __n) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1))) ;
extern char  *strcpy(char *__restrict __dest, __const char *__restrict __src) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;


extern char  *strncpy(char *__restrict __dest, __const char *__restrict __src, size_t __n) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;




extern char  *strcat(char *__restrict __dest, __const char *__restrict __src) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;


extern char  *strncat(char *__restrict __dest, __const char *__restrict __src, size_t __n) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;



extern int  strcmp(__const char *__s1, __const char *__s2) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1, 2))) ;


extern int  strncmp(__const char *__s1, __const char *__s2, size_t __n) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1, 2))) ;



extern int  strcoll(__const char *__s1, __const char *__s2) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1, 2))) ;


extern size_t  strxfrm(char *__restrict __dest, __const char *__restrict __src, size_t __n) __attribute__((__nothrow__))  __attribute__((__nonnull__ (2))) ;
typedef  struct __locale_struct{


  struct __locale_data  *__locales[13];


  const unsigned short int  *__ctype_b;
  const int  *__ctype_tolower;
  const int  *__ctype_toupper;


  const char  *__names[13];
} *__locale_t;


typedef __locale_t  locale_t;
extern int  strcoll_l(__const char *__s1, __const char *__s2, __locale_t __l) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1, 2, 3))) ;


extern size_t  strxfrm_l(char *__dest, __const char *__src, size_t __n, __locale_t __l) __attribute__((__nothrow__))  __attribute__((__nonnull__ (2, 4))) ;






extern char  *strdup(__const char *__s) __attribute__((__nothrow__))  __attribute__((__malloc__))  __attribute__((__nonnull__ (1))) ;







extern char  *strndup(__const char *__string, size_t __n) __attribute__((__nothrow__))  __attribute__((__malloc__))  __attribute__((__nonnull__ (1))) ;
extern char  *strchr(__const char *__s, int __c) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1))) ;
extern char  *strrchr(__const char *__s, int __c) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1))) ;
extern size_t  strcspn(__const char *__s, __const char *__reject) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1, 2))) ;



extern size_t  strspn(__const char *__s, __const char *__accept) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1, 2))) ;
extern char  *strpbrk(__const char *__s, __const char *__accept) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1, 2))) ;
extern char  *strstr(__const char *__haystack, __const char *__needle) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1, 2))) ;





extern char  *strtok(char *__restrict __s, __const char *__restrict __delim) __attribute__((__nothrow__))  __attribute__((__nonnull__ (2))) ;





extern char  *__strtok_r(char *__restrict __s, __const char *__restrict __delim, char **__restrict __save_ptr) __attribute__((__nothrow__))  __attribute__((__nonnull__ (2, 3))) ;




extern char  *strtok_r(char *__restrict __s, __const char *__restrict __delim, char **__restrict __save_ptr) __attribute__((__nothrow__))  __attribute__((__nonnull__ (2, 3))) ;
extern size_t  strlen(__const char *__s) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1))) ;






extern size_t  strnlen(__const char *__string, size_t __maxlen) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1))) ;






extern char  *strerror(int __errnum) __attribute__((__nothrow__)) ;
extern int  strerror_r(int __errnum, char *__buf, size_t __buflen) __asm__ ("__xpg_strerror_r") __attribute__((__nothrow__))  __attribute__((__nonnull__ (2))) ;
extern char  *strerror_l(int __errnum, __locale_t __l) __attribute__((__nothrow__)) ;





extern void  __bzero(void *__s, size_t __n) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;



extern void  bcopy(__const void *__src, void *__dest, size_t __n) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;



extern void  bzero(void *__s, size_t __n) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1))) ;


extern int  bcmp(__const void *__s1, __const void *__s2, size_t __n) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1, 2))) ;
extern char  *index(__const char *__s, int __c) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1))) ;
extern char  *rindex(__const char *__s, int __c) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1))) ;





extern int  ffs(int __i) __attribute__((__nothrow__))  __attribute__((__const__)) ;
extern int  strcasecmp(__const char *__s1, __const char *__s2) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1, 2))) ;



extern int  strncasecmp(__const char *__s1, __const char *__s2, size_t __n) __attribute__((__nothrow__))  __attribute__((__pure__))  __attribute__((__nonnull__ (1, 2))) ;
extern char  *strsep(char **__restrict __stringp, __const char *__restrict __delim) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;






extern char  *strsignal(int __sig) __attribute__((__nothrow__)) ;


extern char  *__stpcpy(char *__restrict __dest, __const char *__restrict __src) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;

extern char  *stpcpy(char *__restrict __dest, __const char *__restrict __src) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;




extern char  *__stpncpy(char *__restrict __dest, __const char *__restrict __src, size_t __n) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;


extern char  *stpncpy(char *__restrict __dest, __const char *__restrict __src, size_t __n) __attribute__((__nothrow__))  __attribute__((__nonnull__ (1, 2))) ;
typedef  struct __belooga_anonymous_type__3024{

  unsigned char  _x[4] __attribute__((__aligned__(4))) ;
} omp_lock_t;


typedef  struct __belooga_anonymous_type__3028{

  unsigned char  _x[8 + sizeof (void *)] __attribute__((__aligned__(sizeof (void *)))) ;
} omp_nest_lock_t;



typedef  enum omp_sched_t{

omp_sched_static = 1, omp_sched_dynamic = 2, omp_sched_guided = 3, omp_sched_auto = 4}
omp_sched_t;
extern void  omp_set_num_threads(int ) __attribute__((__nothrow__)) ;
extern int  omp_get_num_threads(void ) __attribute__((__nothrow__)) ;
extern int  omp_get_max_threads(void ) __attribute__((__nothrow__)) ;
extern int  omp_get_thread_num(void ) __attribute__((__nothrow__)) ;
extern int  omp_get_num_procs(void ) __attribute__((__nothrow__)) ;

extern int  omp_in_parallel(void ) __attribute__((__nothrow__)) ;

extern void  omp_set_dynamic(int ) __attribute__((__nothrow__)) ;
extern int  omp_get_dynamic(void ) __attribute__((__nothrow__)) ;

extern void  omp_set_nested(int ) __attribute__((__nothrow__)) ;
extern int  omp_get_nested(void ) __attribute__((__nothrow__)) ;

extern void  omp_init_lock(omp_lock_t *) __attribute__((__nothrow__)) ;
extern void  omp_destroy_lock(omp_lock_t *) __attribute__((__nothrow__)) ;
extern void  omp_set_lock(omp_lock_t *) __attribute__((__nothrow__)) ;
extern void  omp_unset_lock(omp_lock_t *) __attribute__((__nothrow__)) ;
extern int  omp_test_lock(omp_lock_t *) __attribute__((__nothrow__)) ;

extern void  omp_init_nest_lock(omp_nest_lock_t *) __attribute__((__nothrow__)) ;
extern void  omp_destroy_nest_lock(omp_nest_lock_t *) __attribute__((__nothrow__)) ;
extern void  omp_set_nest_lock(omp_nest_lock_t *) __attribute__((__nothrow__)) ;
extern void  omp_unset_nest_lock(omp_nest_lock_t *) __attribute__((__nothrow__)) ;
extern int  omp_test_nest_lock(omp_nest_lock_t *) __attribute__((__nothrow__)) ;

extern double  omp_get_wtime(void ) __attribute__((__nothrow__)) ;
extern double  omp_get_wtick(void ) __attribute__((__nothrow__)) ;

void  omp_set_schedule(omp_sched_t , int ) __attribute__((__nothrow__)) ;
void  omp_get_schedule(omp_sched_t *, int *) __attribute__((__nothrow__)) ;
int  omp_get_thread_limit(void ) __attribute__((__nothrow__)) ;
void  omp_set_max_active_levels(int ) __attribute__((__nothrow__)) ;
int  omp_get_max_active_levels(void ) __attribute__((__nothrow__)) ;
int  omp_get_level(void ) __attribute__((__nothrow__)) ;
int  omp_get_ancestor_thread_num(int ) __attribute__((__nothrow__)) ;
int  omp_get_team_size(int ) __attribute__((__nothrow__)) ;
int  omp_get_active_level(void ) __attribute__((__nothrow__)) ;
double  max_diff(double *, double *, int );
double  stencil();

int main(int argc, char **argv){
  int  i = 0, reps = 10;
  double  tmp = 0;
  char  *name = "stencil";
  double  times[10];

  printf("%d \n", reps);
  for (i = 0 ; i < reps ; i++)    {
      tmp = stencil();
      if (tmp ==  -10000)        {
          printf("Memory allocation failure in %s\n", name);
          times[i] = 0;
        }
      else
      if (tmp ==  -11000)        {
          printf("CPU/GPU mismatch in %s\n", name);
          times[i] = 0;
        }
      else
      {
        times[i] = tmp;
      }
    }
  double  tt = 0.0;
  for (i = 0 ; i < reps ; i++)
    tt += times[i];

  printf("Total time\t%f\t 1st time:\t %f\n", tt, times[0]);
}
void __hmpp_acc_region__x2bhsmxg(int sz, int __hmpp_addr__i[1], int __hmpp_addr__j[1], int __hmpp_addr__k[1], int n, double fac, double *a0, double *a1)
{
  int  k = *__hmpp_addr__k;
  int  j = *__hmpp_addr__j;
  int  i = *__hmpp_addr__i;
  /* prologue placeholder */

  for (i = 1 ; i < n + 1 ; i++)    {

      for (j = 1 ; j < n + 1 ; j++)        {

          for (k = 1 ; k < n + 1 ; k++)            {



              a1[i * sz * sz + j * sz + k] = (a0[i * sz * sz + (j - 1) * sz + k] + a0[i * sz * sz + (j + 1) * sz + k] + a0[(i - 1) * sz * sz + j * sz + k] + a0[(i + 1) * sz * sz + j * sz + k] + a0[(i - 1) * sz * sz + (j - 1) * sz + k] + a0[(i - 1) * sz * sz + (j + 1) * sz + k] + a0[(i + 1) * sz * sz + (j - 1) * sz + k] + a0[(i + 1) * sz * sz + (j + 1) * sz + k] + a0[i * sz * sz + (j - 1) * sz + (k - 1)] + a0[i * sz * sz + (j + 1) * sz + (k - 1)] + a0[(i - 1) * sz * sz + j * sz + (k - 1)] + a0[(i + 1) * sz * sz + j * sz + (k - 1)] + a0[(i - 1) * sz * sz + (j - 1) * sz + (k - 1)] + a0[(i - 1) * sz * sz + (j + 1) * sz + (k - 1)] + a0[(i + 1) * sz * sz + (j - 1) * sz + (k - 1)] + a0[(i + 1) * sz * sz + (j + 1) * sz + (k - 1)] + a0[i * sz * sz + (j - 1) * sz + (k + 1)] + a0[i * sz * sz + (j + 1) * sz + (k + 1)] + a0[(i - 1) * sz * sz + j * sz + (k + 1)] + a0[(i + 1) * sz * sz + j * sz + (k + 1)] + a0[(i - 1) * sz * sz + (j - 1) * sz + (k + 1)] + a0[(i - 1) * sz * sz + (j + 1) * sz + (k + 1)] + a0[(i + 1) * sz * sz + (j - 1) * sz + (k + 1)] + a0[(i + 1) * sz * sz + (j + 1) * sz + (k + 1)] + a0[i * sz * sz + j * sz + (k - 1)] + a0[i * sz * sz + j * sz + (k + 1)]) * fac;
            }
        }
    }
  *__hmpp_addr__i = i;
  *__hmpp_addr__j = j;
  *__hmpp_addr__k = k;
  /* epilogue placeholder */}
void __hmpp_acc_region__wmf7vvd0(int sz, int __hmpp_addr__i[1], int __hmpp_addr__j[1], int __hmpp_addr__k[1], int n, double *a0, double *a1)
{
  int  k = *__hmpp_addr__k;
  int  j = *__hmpp_addr__j;
  int  i = *__hmpp_addr__i;
  /* prologue placeholder */

  for (i = 1 ; i < n + 1 ; i++)    {

      for (j = 1 ; j < n + 1 ; j++)        {

          for (k = 1 ; k < n + 1 ; k++)            {
              a0[i * sz * sz + j * sz + k] = a1[i * sz * sz + j * sz + k];
            }
        }
    }
  *__hmpp_addr__i = i;
  *__hmpp_addr__j = j;
  *__hmpp_addr__k = k;
  /* epilogue placeholder */}
double stencil(){
  unsigned int  datasize = 1048576;
  int  sz = cbrt((datasize / sizeof (double )) / 2);
  int  i, j, k, iter;
  int  n = sz - 2;
  double  fac = (1. / 26);
  double  t1, t2;
  double  md;

  double  *a0 = (double *) malloc(sizeof (double ) * sz * sz * sz);
  double  *device_result = (double *) malloc(sizeof (double ) * sz * sz * sz);
  double  *a1 = (double *) malloc(sizeof (double ) * sz * sz * sz);
  double  *host_result = (double *) malloc(sizeof (double ) * sz * sz * sz);
  double  *a0_init = (double *) malloc(sizeof (double ) * sz * sz * sz);

  if (a0 == ((void *) 0) || device_result == ((void *) 0) || a1 == ((void *) 0) || host_result == ((void *) 0) || a0_init == ((void *) 0))    {
      return ( -10000);
    }


  for (i = 0 ; i < sz ; i++)    {
      for (j = 0 ; j < sz ; j++)        {
          for (k = 0 ; k < sz ; k++)            {
              a0[i * sz * sz + j * sz + k] = 0.0;
            }
        }
    }


  for (i = 1 ; i < n + 1 ; i++)    {
      for (j = 1 ; j < n + 1 ; j++)        {
          for (k = 1 ; k < n + 1 ; k++)            {
              a0[i * sz * sz + j * sz + k] = (double ) rand() / (double ) (1.0 + 2147483647);
            }
        }
    }


  for (i = 0 ; i < sz ; i++)    {
      for (j = 0 ; j < sz ; j++)        {
          for (k = 0 ; k < sz ; k++)            {
              a0_init[i * sz * sz + j * sz + k] = a0[i * sz * sz + j * sz + k];
            }
        }
    }



  for (iter = 0 ; iter < 10 ; iter++)    {

      for (i = 1 ; i < n + 1 ; i++)        {
          for (j = 1 ; j < n + 1 ; j++)            {
              for (k = 1 ; k < n + 1 ; k++)                {



                  a1[i * sz * sz + j * sz + k] = (a0[i * sz * sz + (j - 1) * sz + k] + a0[i * sz * sz + (j + 1) * sz + k] + a0[(i - 1) * sz * sz + j * sz + k] + a0[(i + 1) * sz * sz + j * sz + k] + a0[(i - 1) * sz * sz + (j - 1) * sz + k] + a0[(i - 1) * sz * sz + (j + 1) * sz + k] + a0[(i + 1) * sz * sz + (j - 1) * sz + k] + a0[(i + 1) * sz * sz + (j + 1) * sz + k] + a0[i * sz * sz + (j - 1) * sz + (k - 1)] + a0[i * sz * sz + (j + 1) * sz + (k - 1)] + a0[(i - 1) * sz * sz + j * sz + (k - 1)] + a0[(i + 1) * sz * sz + j * sz + (k - 1)] + a0[(i - 1) * sz * sz + (j - 1) * sz + (k - 1)] + a0[(i - 1) * sz * sz + (j + 1) * sz + (k - 1)] + a0[(i + 1) * sz * sz + (j - 1) * sz + (k - 1)] + a0[(i + 1) * sz * sz + (j + 1) * sz + (k - 1)] + a0[i * sz * sz + (j - 1) * sz + (k + 1)] + a0[i * sz * sz + (j + 1) * sz + (k + 1)] + a0[(i - 1) * sz * sz + j * sz + (k + 1)] + a0[(i + 1) * sz * sz + j * sz + (k + 1)] + a0[(i - 1) * sz * sz + (j - 1) * sz + (k + 1)] + a0[(i - 1) * sz * sz + (j + 1) * sz + (k + 1)] + a0[(i + 1) * sz * sz + (j - 1) * sz + (k + 1)] + a0[(i + 1) * sz * sz + (j + 1) * sz + (k + 1)] + a0[i * sz * sz + j * sz + (k - 1)] + a0[i * sz * sz + j * sz + (k + 1)]) * fac;
                }
            }
        }

      for (i = 1 ; i < n + 1 ; i++)        {
          for (j = 1 ; j < n + 1 ; j++)            {
              for (k = 1 ; k < n + 1 ; k++)                {
                  a0[i * sz * sz + j * sz + k] = a1[i * sz * sz + j * sz + k];
                }
            }
        }
    }


  for (i = 0 ; i < sz ; i++)    {
      for (j = 0 ; j < sz ; j++)        {
          for (k = 0 ; k < sz ; k++)            {
              host_result[i * sz * sz + j * sz + k] = a0[i * sz * sz + j * sz + k];
            }
        }
    }


  for (i = 0 ; i < sz ; i++)    {
      for (j = 0 ; j < sz ; j++)        {
          for (k = 0 ; k < sz ; k++)            {
              a0[i * sz * sz + j * sz + k] = a0_init[i * sz * sz + j * sz + k];
            }
        }
    }

  t1 = omp_get_wtime();

  openacci_enter_region(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 130,
      /* region_kind  = */ 4 /* data */,
      /* num_args     = */ 9,
      /* async_mode   = */ 0 /* SYNC */,
      /* queue_id     = */ 0 /* meaningless */);
if (1)
{
  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 130,
      /* string       = */ "a0",
      /* address      = */ & (a0)[0],
      /* start        = */ 0,
      /* length       = */ sz*sz*sz,
      /* element_size = */ sizeof (a0)[0],
      /* mode         = */ 11 /* copy */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 130,
      /* string       = */ "a1",
      /* address      = */ & (a1)[0],
      /* start        = */ 0,
      /* length       = */ sz*sz*sz,
      /* element_size = */ sizeof (a1)[0],
      /* mode         = */ 8 /* create */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 130,
      /* string       = */ "fac",
      /* address      = */ & (fac),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (fac),
      /* mode         = */ 9 /* copyin */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 130,
      /* string       = */ "i",
      /* address      = */ & (i),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (i),
      /* mode         = */ 8 /* create */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 130,
      /* string       = */ "iter",
      /* address      = */ & (iter),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (iter),
      /* mode         = */ 8 /* create */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 130,
      /* string       = */ "j",
      /* address      = */ & (j),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (j),
      /* mode         = */ 8 /* create */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 130,
      /* string       = */ "k",
      /* address      = */ & (k),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (k),
      /* mode         = */ 8 /* create */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 130,
      /* string       = */ "n",
      /* address      = */ & (n),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (n),
      /* mode         = */ 9 /* copyin */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 130,
      /* string       = */ "sz",
      /* address      = */ & (sz),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (sz),
      /* mode         = */ 9 /* copyin */);

}
else
{
}

  {

    for (iter = 0 ; iter < 10 ; iter++)      {

  openacci_enter_region(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 134,
      /* region_kind  = */ 17 /* parallel loop */,
      /* num_args     = */ 8,
      /* async_mode   = */ 0 /* SYNC */,
      /* queue_id     = */ 0 /* meaningless */);
if (1)
{
  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 134,
      /* string       = */ "sz",
      /* address      = */ & (sz),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (sz),
      /* mode         = */ 4 /* value */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 134,
      /* string       = */ "i",
      /* address      = */ & (i),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (i),
      /* mode         = */ 155 /* ipcopy */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 134,
      /* string       = */ "j",
      /* address      = */ & (j),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (j),
      /* mode         = */ 155 /* ipcopy */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 134,
      /* string       = */ "k",
      /* address      = */ & (k),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (k),
      /* mode         = */ 155 /* ipcopy */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 134,
      /* string       = */ "n",
      /* address      = */ & (n),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (n),
      /* mode         = */ 4 /* value */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 134,
      /* string       = */ "fac",
      /* address      = */ & (fac),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (fac),
      /* mode         = */ 4 /* value */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 134,
      /* string       = */ "a0",
      /* address      = */ & (a0)[0],
      /* start        = */ 0,
      /* length       = */ -1,
      /* element_size = */ sizeof (a0)[0],
      /* mode         = */ 155 /* ipcopy */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 134,
      /* string       = */ "a1",
      /* address      = */ & (a1)[0],
      /* start        = */ 0,
      /* length       = */ -1,
      /* element_size = */ sizeof (a1)[0],
      /* mode         = */ 155 /* ipcopy */);

  openacci_call(
      /* file_name      = */ "stencil.c",
      /* line_number    = */ 134,
      /* function       = */ "__hmpp_acc_region__x2bhsmxg");
}
else
{
  openacci_fallback(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 134,
      /* function     = */ "__hmpp_acc_region__x2bhsmxg");

        __hmpp_acc_region__x2bhsmxg(sz, &i, &j, &k, n, fac, a0, a1);

}
  openacci_leave_region(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 134);


  openacci_enter_region(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 148,
      /* region_kind  = */ 17 /* parallel loop */,
      /* num_args     = */ 7,
      /* async_mode   = */ 0 /* SYNC */,
      /* queue_id     = */ 0 /* meaningless */);
if (1)
{
  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 148,
      /* string       = */ "sz",
      /* address      = */ & (sz),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (sz),
      /* mode         = */ 4 /* value */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 148,
      /* string       = */ "i",
      /* address      = */ & (i),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (i),
      /* mode         = */ 155 /* ipcopy */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 148,
      /* string       = */ "j",
      /* address      = */ & (j),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (j),
      /* mode         = */ 155 /* ipcopy */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 148,
      /* string       = */ "k",
      /* address      = */ & (k),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (k),
      /* mode         = */ 155 /* ipcopy */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 148,
      /* string       = */ "n",
      /* address      = */ & (n),
      /* start        = */ 0,
      /* length       = */ 1,
      /* element_size = */ sizeof (n),
      /* mode         = */ 4 /* value */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 148,
      /* string       = */ "a0",
      /* address      = */ & (a0)[0],
      /* start        = */ 0,
      /* length       = */ -1,
      /* element_size = */ sizeof (a0)[0],
      /* mode         = */ 155 /* ipcopy */);

  openacci_push_data(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 148,
      /* string       = */ "a1",
      /* address      = */ & (a1)[0],
      /* start        = */ 0,
      /* length       = */ -1,
      /* element_size = */ sizeof (a1)[0],
      /* mode         = */ 155 /* ipcopy */);

  openacci_call(
      /* file_name      = */ "stencil.c",
      /* line_number    = */ 148,
      /* function       = */ "__hmpp_acc_region__wmf7vvd0");
}
else
{
  openacci_fallback(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 148,
      /* function     = */ "__hmpp_acc_region__wmf7vvd0");

        __hmpp_acc_region__wmf7vvd0(sz, &i, &j, &k, n, a0, a1);

}
  openacci_leave_region(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 148);

      }
  }

  openacci_leave_region(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 130);


if (1)
{
  openacci_wait(
      /* file_name    = */ "stencil.c",
      /* line_number  = */ 162,
      /* async_mode   = */ 2 /* FULL_ASYNC */,
      /* queue_id     = */ 0 /* meaningless */);

}

  t2 = omp_get_wtime();

  memcpy(&device_result[0], &a0[0], sizeof (double ) * sz * sz * sz);
  md = max_diff(&host_result[0], &device_result[0], sz);


  free(a0);
  free(a0_init);
  free(a1);
  free(host_result);
  free(device_result);

  if (md < 1.0e-15)    {

      return (t2 - t1);
    }
  else
  {

    return ( -11000);
  }
}




double max_diff(double *array1, double *array2, int sz){
  double  tmpdiff, diff;
  int  i, j, k;
  int  n = sz - 2;
  diff = 0.0;

  for (i = 1 ; i < n + 1 ; i++)    {
      for (j = 1 ; j < n + 1 ; j++)        {
          for (k = 1 ; k < n + 1 ; k++)            {
              tmpdiff = fabs(array1[i * sz * sz + j * sz + k] - array2[i * sz * sz + j * sz + k]);
              if (tmpdiff > diff)                diff = tmpdiff;
            }
        }
    }

  return diff;
}

/* HMPP global lookup function */
static struct hmpprti_grouplet * hmppsi_lookup(void)
{
  return hmpprti_lookup_grouplet("");
}



