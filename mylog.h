#ifndef MYLOG_COMPAT__h
#define MYLOG_COMPAT__h

/* Color codes for enhanced debugging. */
static const char _nrm[] = {0x1b, '[', '0', ';', '3', '9', 'm', 0}; /* normal/reset */
static const char _blk[] = {0x1b, '[', '1', ';', '3', '0', 'm', 0}; /* black */
static const char _red[] = {0x1b, '[', '1', ';', '3', '1', 'm', 0}; /* red */
static const char _grn[] = {0x1b, '[', '0', ';', '3', '2', 'm', 0}; /* green */
static const char _ylw[] = {0x1b, '[', '1', ';', '3', '3', 'm', 0}; /* yellow */
static const char _blu[] = {0x1b, '[', '1', ';', '3', '4', 'm', 0}; /* blue */
static const char _pur[] = {0x1b, '[', '0', ';', '3', '5', 'm', 0}; /* purple */
static const char _cya[] = {0x1b, '[', '0', ';', '3', '6', 'm', 0}; /* cyan */
static const char _wht[] = {0x1b, '[', '0', ';', '0', '1', 'm', 0}; /* bold white */
static const char _udl[] = {0x1b, '[', '0', ';', '0', '4', 'm', 0}; /* underlined */
static const char _inv[] = {0x1b, '[', '0', ';', '0', '7', 'm', 0}; /* inverted/shaded */

/* Bold */
static const char b_nrm[] = {0x1b, '[', '1', ';', '3', '9', 'm', 0}; /* normal */
static const char b_blk[] = {0x1b, '[', '1', ';', '3', '0', 'm', 0}; /* black */
static const char b_red[] = {0x1b, '[', '1', ';', '3', '1', 'm', 0}; /* red */
static const char b_grn[] = {0x1b, '[', '1', ';', '3', '2', 'm', 0}; /* green */
static const char b_ylw[] = {0x1b, '[', '1', ';', '3', '3', 'm', 0}; /* yellow */
static const char b_blu[] = {0x1b, '[', '1', ';', '3', '4', 'm', 0}; /* blue */
static const char b_pur[] = {0x1b, '[', '1', ';', '3', '5', 'm', 0}; /* purple */
static const char b_cya[] = {0x1b, '[', '1', ';', '3', '6', 'm', 0}; /* cyan */
static const char b_wht[] = {0x1b, '[', '1', ';', '0', '1', 'm', 0}; /* bold white */
static const char b_udl[] = {0x1b, '[', '1', ';', '0', '4', 'm', 0}; /* underlined */
static const char b_inv[] = {0x1b, '[', '1', ';', '0', '7', 'm', 0}; /* inverted/shaded */

/* black on ... */
static const char blk_nrm[] = {0x1b, '[', '7', ';', '3', '9', 'm', 0}; /* normal */
static const char blk_blk[] = {0x1b, '[', '7', ';', '3', '0', 'm', 0}; /* black */
static const char blk_red[] = {0x1b, '[', '7', ';', '3', '1', 'm', 0}; /* red */
static const char blk_grn[] = {0x1b, '[', '7', ';', '3', '2', 'm', 0}; /* green */
static const char blk_ylw[] = {0x1b, '[', '7', ';', '3', '3', 'm', 0}; /* yellow */
static const char blk_blu[] = {0x1b, '[', '7', ';', '3', '4', 'm', 0}; /* blue */
static const char blk_pur[] = {0x1b, '[', '7', ';', '3', '5', 'm', 0}; /* purple */
static const char blk_cya[] = {0x1b, '[', '7', ';', '3', '6', 'm', 0}; /* cyan */
static const char blk_wht[] = {0x1b, '[', '7', ';', '0', '1', 'm', 0}; /* bold white */

 // \\033[7;36;40m  - black text on cyan
 // \\033[1;36;49m  - bold cyan


#define c_paintf(color, ...) do { \
   printf( color ); printf(__VA_ARGS__); printf( _nrm ); \
} while(0)

/* standard */
#define c_paintf_nrm(...)    c_paintf(_nrm, __VA_ARGS__)
#define c_paintf_red(...)    c_paintf(_red, __VA_ARGS__)
#define c_paintf_grn(...)    c_paintf(_grn, __VA_ARGS__)
#define c_paintf_blk(...)    c_paintf(_blk, __VA_ARGS__)
#define c_paintf_ylw(...)    c_paintf(_ylw, __VA_ARGS__)
#define c_paintf_blu(...)    c_paintf(_blu, __VA_ARGS__)
#define c_paintf_pur(...)    c_paintf(_pur, __VA_ARGS__)
#define c_paintf_cya(...)    c_paintf(_cya, __VA_ARGS__)
#define c_paintf_wht(...)    c_paintf(_wht, __VA_ARGS__)
#define c_paintf_inv(...)    c_paintf(_inv, __VA_ARGS__)
#define c_paintf_udl(...)    c_paintf(_udl, __VA_ARGS__)

/* bold */
#define c_paintf_nrm_b(...)    c_paintf(b_nrm, __VA_ARGS__)
#define c_paintf_red_b(...)    c_paintf(b_red, __VA_ARGS__)
#define c_paintf_grn_b(...)    c_paintf(b_grn, __VA_ARGS__)
#define c_paintf_blk_b(...)    c_paintf(b_blk, __VA_ARGS__)
#define c_paintf_ylw_b(...)    c_paintf(b_ylw, __VA_ARGS__)
#define c_paintf_blu_b(...)    c_paintf(b_blu, __VA_ARGS__)
#define c_paintf_pur_b(...)    c_paintf(b_pur, __VA_ARGS__)
#define c_paintf_cya_b(...)    c_paintf(b_cya, __VA_ARGS__)
#define c_paintf_wht_b(...)    c_paintf(b_wht, __VA_ARGS__)
#define c_paintf_inv_b(...)    c_paintf(b_inv, __VA_ARGS__)
#define c_paintf_udl_b(...)    c_paintf(b_udl, __VA_ARGS__)

/* bold */
#define c_paintf_blk_nrm(...)    c_paintf(blk_nrm, __VA_ARGS__)
#define c_paintf_blk_red(...)    c_paintf(blk_red, __VA_ARGS__)
#define c_paintf_blk_grn(...)    c_paintf(blk_grn, __VA_ARGS__)
#define c_paintf_blk_blk(...)    c_paintf(blk_blk, __VA_ARGS__)
#define c_paintf_blk_ylw(...)    c_paintf(blk_ylw, __VA_ARGS__)
#define c_paintf_blk_blu(...)    c_paintf(blk_blu, __VA_ARGS__)
#define c_paintf_blk_pur(...)    c_paintf(blk_pur, __VA_ARGS__)
#define c_paintf_blk_cya(...)    c_paintf(blk_cya, __VA_ARGS__)
#define c_paintf_blk_wht(...)    c_paintf(blk_wht, __VA_ARGS__)

#define logc      c_paintf_blu
#define logwarnc  c_paintf_ylw
#define logerrc   c_paintf_red
#define logokc    c_paintf_grn
#define loginfoc  c_paintf_wht

#endif
