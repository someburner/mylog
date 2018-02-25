#ifndef MYLOG_COMPAT__h
#define MYLOG_COMPAT__h

#define CLR_OFFETS_MAP(XX) \
    XX(0,  BLK, blk, '0' ) \
    XX(1,  RED, red, '1'  ) \
    XX(2,  GRN, grn, '2'  ) \
    XX(3,  YLW, ylw, '3'  ) \
    XX(4,  BLU, blu, '4'  ) \
    XX(5,  PUR, pur, '5'  ) \
    XX(6,  CYA, cya, '6'  ) \
    XX(7,  WHT, wht, '7'  ) \
    XX(8,  GRY, gry, '8'  ) \
    XX(9,  NRM, nrm, '9'  )

/* Standard color set */
#define XX(num, unames, lnames, fch) static const char _##lnames##_std[] = {0x1b,'[', '0', ';', '3', fch, 'm', 0};
CLR_OFFETS_MAP(XX)
#undef XX

/* Bright color set */
#define XX(num, unames, lnames, fch) static const char _##lnames##_bri[] = {0x1b,'[', '0', ';', '9', fch, 'm', 0};
CLR_OFFETS_MAP(XX)
#undef XX

/* bold ... */
#define XX(num, unames, lnames, fch) static const char _##lnames##_bld[] = {0x1b,'[', '1', ';', '9', fch, 'm', 0};
CLR_OFFETS_MAP(XX)
#undef XX

/* black on ... */
#define XX(num, unames, lnames, fch) static const char blk_on_##lnames##_[] = {0x1b,'[', '7', ';', '3', fch, ';', '4', '4', 'm', 0};
CLR_OFFETS_MAP(XX)
#undef XX

/* white on ... */
#define XX(num, unames, lnames, fch) static const char wht_on_##lnames##_[] = {0x1b,'[', '0', ';', '3', '9', ';', '4', fch, 'm', 0};
CLR_OFFETS_MAP(XX)
#undef XX

/* bold white on ... */
#define XX(num, unames, lnames, fch) static const char bwht_on_##lnames##_[] = {0x1b,'[', '1', ';', '3', '9', ';', '4', fch, 'm', 0};
CLR_OFFETS_MAP(XX)
#undef XX

/* ... on blu */
#define XX(num, unames, lnames, fch) static const char _##lnames##_on_blu[] = {0x1b,'[', '1', ';', '3', fch, ';', '4', '4', 'm', 0};
CLR_OFFETS_MAP(XX)
#undef XX

static const char __udl[] = {0x1b, '[', '0', ';', '0', '4', 'm', 0}; /* underlined */
static const char __inv[] = {0x1b, '[', '0', ';', '0', '7', 'm', 0}; /* inverted/shaded */
static const char _udl_bld[] = {0x1b, '[', '1', ';', '0', '4', 'm', 0}; /* underlined */
static const char _inv_bld[] = {0x1b, '[', '1', ';', '0', '7', 'm', 0}; /* inverted/shaded */

#define c_paintf(color, ...) do { \
   printf( color ); printf(__VA_ARGS__); printf( _nrm_std ); \
} while(0)


/* non-macro -- std */
#define c_paintf_inv(...)    c_paintf(__inv, __VA_ARGS__)
#define c_paintf_udl(...)    c_paintf(__udl, __VA_ARGS__)
/* non-macro -- bld */
#define c_paintf_inv_bld(...)    c_paintf(_inv_bld, __VA_ARGS__)
#define c_paintf_udl_bld(...)    c_paintf(_udl_bld, __VA_ARGS__)
/* non-macro -- bri */

/* standard */
#define c_paintf_nrm(...)    c_paintf(_nrm_std, __VA_ARGS__)
#define c_paintf_red(...)    c_paintf(_red_std, __VA_ARGS__)
#define c_paintf_grn(...)    c_paintf(_grn_std, __VA_ARGS__)
#define c_paintf_blk(...)    c_paintf(_blk_std, __VA_ARGS__)
#define c_paintf_ylw(...)    c_paintf(_ylw_std, __VA_ARGS__)
#define c_paintf_blu(...)    c_paintf(_blu_std, __VA_ARGS__)
#define c_paintf_pur(...)    c_paintf(_pur_std, __VA_ARGS__)
#define c_paintf_cya(...)    c_paintf(_cya_std, __VA_ARGS__)
#define c_paintf_wht(...)    c_paintf(_wht_std, __VA_ARGS__)

/* bright */
#define c_paintf_bri_nrm(...)    c_paintf(_nrm_bri, __VA_ARGS__)
#define c_paintf_bri_red(...)    c_paintf(_red_bri, __VA_ARGS__)
#define c_paintf_bri_grn(...)    c_paintf(_grn_bri, __VA_ARGS__)
#define c_paintf_bri_blk(...)    c_paintf(_blk_bri, __VA_ARGS__)
#define c_paintf_bri_ylw(...)    c_paintf(_ylw_bri, __VA_ARGS__)
#define c_paintf_bri_blu(...)    c_paintf(_blu_bri, __VA_ARGS__)
#define c_paintf_bri_pur(...)    c_paintf(_pur_bri, __VA_ARGS__)
#define c_paintf_bri_cya(...)    c_paintf(_cya_bri, __VA_ARGS__)
#define c_paintf_bri_wht(...)    c_paintf(_wht_bri, __VA_ARGS__)

/* bold */
#define c_paintf_nrm_bld(...)    c_paintf(_nrm_bld, __VA_ARGS__)
#define c_paintf_red_bld(...)    c_paintf(_red_bld, __VA_ARGS__)
#define c_paintf_grn_bld(...)    c_paintf(_grn_bld, __VA_ARGS__)
#define c_paintf_blk_bld(...)    c_paintf(_blk_bld, __VA_ARGS__)
#define c_paintf_ylw_bld(...)    c_paintf(_ylw_bld, __VA_ARGS__)
#define c_paintf_blu_bld(...)    c_paintf(_blu_bld, __VA_ARGS__)
#define c_paintf_pur_bld(...)    c_paintf(_pur_bld, __VA_ARGS__)
#define c_paintf_cya_bld(...)    c_paintf(_cya_bld, __VA_ARGS__)
#define c_paintf_wht_bld(...)    c_paintf(_wht_bld, __VA_ARGS__)

/* blk on ... */
#define c_paintf_blk_nrm(...)    c_paintf(blk_on_nrm_, __VA_ARGS__)
#define c_paintf_blk_red(...)    c_paintf(blk_on_red_, __VA_ARGS__)
#define c_paintf_blk_grn(...)    c_paintf(blk_on_grn_, __VA_ARGS__)
#define c_paintf_blk_blk(...)    c_paintf(blk_on_blk_, __VA_ARGS__)
#define c_paintf_blk_ylw(...)    c_paintf(blk_on_ylw_, __VA_ARGS__)
#define c_paintf_blk_blu(...)    c_paintf(blk_on_blu_, __VA_ARGS__)
#define c_paintf_blk_pur(...)    c_paintf(blk_on_pur_, __VA_ARGS__)
#define c_paintf_blk_cya(...)    c_paintf(blk_on_cya_, __VA_ARGS__)
#define c_paintf_blk_wht(...)    c_paintf(blk_on_wht_, __VA_ARGS__)

/* wht on ... */
#define c_paintf_wht_nrm(...)    c_paintf(wht_on_nrm_, __VA_ARGS__)
#define c_paintf_wht_red(...)    c_paintf(wht_on_red_, __VA_ARGS__)
#define c_paintf_wht_grn(...)    c_paintf(wht_on_grn_, __VA_ARGS__)
#define c_paintf_wht_blk(...)    c_paintf(wht_on_blk_, __VA_ARGS__)
#define c_paintf_wht_ylw(...)    c_paintf(wht_on_ylw_, __VA_ARGS__)
#define c_paintf_wht_blu(...)    c_paintf(wht_on_blu_, __VA_ARGS__)
#define c_paintf_wht_pur(...)    c_paintf(wht_on_pur_, __VA_ARGS__)
#define c_paintf_wht_cya(...)    c_paintf(wht_on_cya_, __VA_ARGS__)

/* bold wht on ... */
#define c_paintf_bwht_nrm(...)    c_paintf(bwht_on_nrm_, __VA_ARGS__)
#define c_paintf_bwht_red(...)    c_paintf(bwht_on_red_, __VA_ARGS__)
#define c_paintf_bwht_grn(...)    c_paintf(bwht_on_grn_, __VA_ARGS__)
#define c_paintf_bwht_blk(...)    c_paintf(bwht_on_blk_, __VA_ARGS__)
#define c_paintf_bwht_ylw(...)    c_paintf(bwht_on_ylw_, __VA_ARGS__)
#define c_paintf_bwht_blu(...)    c_paintf(bwht_on_blu_, __VA_ARGS__)
#define c_paintf_bwht_pur(...)    c_paintf(bwht_on_pur_, __VA_ARGS__)
#define c_paintf_bwht_cya(...)    c_paintf(bwht_on_cya_, __VA_ARGS__)

/* ... on blu */
#define c_paintf_nrm_blu(...)    c_paintf(_nrm_on_blu, __VA_ARGS__)
#define c_paintf_red_blu(...)    c_paintf(_red_on_blu, __VA_ARGS__)
#define c_paintf_grn_blu(...)    c_paintf(_grn_on_blu, __VA_ARGS__)
#define c_paintf_ylw_blu(...)    c_paintf(_ylw_on_blu, __VA_ARGS__)
#define c_paintf_blu_blu(...)    c_paintf(_blu_on_blu, __VA_ARGS__)
#define c_paintf_pur_blu(...)    c_paintf(_pur_on_blu, __VA_ARGS__)
#define c_paintf_cya_blu(...)    c_paintf(_cya_on_blu, __VA_ARGS__)

#define logc      c_paintf_blu
#define logwarnc  c_paintf_ylw
#define logerrc   c_paintf_red
#define logokc    c_paintf_grn
#define loginfoc  c_paintf_wht

#endif
