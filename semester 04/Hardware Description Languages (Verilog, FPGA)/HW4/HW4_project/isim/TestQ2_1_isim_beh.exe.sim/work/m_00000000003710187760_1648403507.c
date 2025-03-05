/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "E:/rasool/IUT/t4/FPGA/HWs/HW4/HW4_project/TestQ2_1.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static int ng3[] = {3, 0};



static void Always_50_0(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 5248U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(50, ng0);

LAB4:    xsi_set_current_line(50, ng0);

LAB5:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 5056);
    xsi_process_wait(t2, 7000LL);
    *((char **)t1) = &&LAB6;

LAB1:    return;
LAB6:    xsi_set_current_line(51, ng0);
    t4 = (t0 + 4168);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB10;

LAB8:    if (*((unsigned int *)t7) == 0)
        goto LAB7;

LAB9:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB10:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB12;

LAB11:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 4168);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB4;

LAB7:    *((unsigned int *)t3) = 1;
    goto LAB10;

LAB12:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB11;

LAB13:    goto LAB2;

}

static void Initial_54_1(char *t0)
{
    char t10[8];
    char *t1;
    char *t2;
    char *t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    int t7;
    char *t8;
    char *t9;
    char *t11;
    char *t12;

LAB0:    t1 = (t0 + 5496U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(54, ng0);

LAB4:    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4328);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(56, ng0);
    t2 = (t0 + 5304);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4328);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(58, ng0);
    t2 = (t0 + 5304);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4328);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(60, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 7844);
    *((int *)t8) = t7;

LAB7:    t9 = (t0 + 7844);
    if (*((int *)t9) > 0)
        goto LAB8;

LAB9:    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(83, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(85, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(87, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(90, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(91, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(92, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(93, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(94, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(95, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(96, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 3848);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(97, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    goto LAB1;

LAB8:    xsi_set_current_line(60, ng0);

LAB10:    xsi_set_current_line(61, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t11 = (t10 + 4);
    *((int *)t11) = 0;
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t10, 0, 0, 32);
    xsi_set_current_line(62, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(63, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(64, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(65, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(66, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(67, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(68, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 2568);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(69, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 2728);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(70, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 2888);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(71, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 3048);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(72, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 3208);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(73, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 3368);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(74, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 3528);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(75, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 3688);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(76, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 3848);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(77, ng0);
    *((int *)t10) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t10 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 4008);
    xsi_vlogvar_assign_value(t3, t10, 0, 0, 32);
    xsi_set_current_line(78, ng0);
    t2 = (t0 + 5304);
    xsi_process_wait(t2, 7000LL);
    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB11:    t2 = (t0 + 7844);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB7;

}


extern void work_m_00000000003710187760_1648403507_init()
{
	static char *pe[] = {(void *)Always_50_0,(void *)Initial_54_1};
	xsi_register_didat("work_m_00000000003710187760_1648403507", "isim/TestQ2_1_isim_beh.exe.sim/work/m_00000000003710187760_1648403507.didat");
	xsi_register_executes(pe);
}
