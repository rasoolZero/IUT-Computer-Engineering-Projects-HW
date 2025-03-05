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
static const char *ng0 = "E:/rasool/IUT/t4/FPGA/HWs/HW4/HW4_project/TestQ1.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static int ng3[] = {20, 0};
static int ng4[] = {2, 0};



static void Always_23_0(char *t0)
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

LAB0:    t1 = (t0 + 3008U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(23, ng0);

LAB4:    xsi_set_current_line(23, ng0);
    t2 = (t0 + 2816);
    xsi_process_wait(t2, 7000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(23, ng0);
    t4 = (t0 + 1928);
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
        goto LAB9;

LAB7:    if (*((unsigned int *)t7) == 0)
        goto LAB6;

LAB8:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB9:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB11;

LAB10:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 1928);
    xsi_vlogvar_wait_assign_value(t24, t3, 0, 0, 1, 0LL);
    goto LAB4;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB11:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB10;

LAB12:    goto LAB2;

}

static void Initial_25_1(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    int t9;
    char *t10;
    char *t11;
    char *t12;

LAB0:    t1 = (t0 + 3256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(25, ng0);

LAB4:    xsi_set_current_line(26, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(27, ng0);
    t2 = (t0 + 3064);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(28, ng0);
    *((int *)t4) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t3 = (t4 + 4);
    *((int *)t3) = 0;
    t5 = (t0 + 1768);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 16);
    xsi_set_current_line(29, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(30, ng0);
    t2 = (t0 + 3064);
    xsi_process_wait(t2, 15000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(31, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(32, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t2 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (~(t6));
    t8 = *((unsigned int *)t2);
    t9 = (t8 & t7);
    t5 = (t0 + 5284);
    *((int *)t5) = t9;

LAB7:    t10 = (t0 + 5284);
    if (*((int *)t10) > 0)
        goto LAB8;

LAB9:    xsi_set_current_line(37, ng0);
    t2 = (t0 + 3064);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB12;
    goto LAB1;

LAB8:    xsi_set_current_line(32, ng0);

LAB10:    xsi_set_current_line(33, ng0);
    *((int *)t4) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t11 = (t4 + 4);
    *((int *)t11) = 0;
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 16);
    xsi_set_current_line(34, ng0);
    *((int *)t4) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t4 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    xsi_set_current_line(35, ng0);
    t2 = (t0 + 3064);
    xsi_process_wait(t2, 7000LL);
    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB11:    t2 = (t0 + 5284);
    t9 = *((int *)t2);
    *((int *)t2) = (t9 - 1);
    goto LAB7;

LAB12:    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(39, ng0);
    *((int *)t4) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t4 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    xsi_set_current_line(40, ng0);
    t2 = (t0 + 3064);
    xsi_process_wait(t2, 15000LL);
    *((char **)t1) = &&LAB13;
    goto LAB1;

LAB13:    xsi_set_current_line(41, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(42, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t2 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (~(t6));
    t8 = *((unsigned int *)t2);
    t9 = (t8 & t7);
    t5 = (t0 + 5288);
    *((int *)t5) = t9;

LAB14:    t10 = (t0 + 5288);
    if (*((int *)t10) > 0)
        goto LAB15;

LAB16:    xsi_set_current_line(47, ng0);
    *((int *)t4) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t4 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    xsi_set_current_line(48, ng0);
    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t10 = (t0 + 1608);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 16);
    xsi_set_current_line(49, ng0);
    t2 = (t0 + 3064);
    xsi_process_wait(t2, 25000LL);
    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB15:    xsi_set_current_line(42, ng0);

LAB17:    xsi_set_current_line(43, ng0);
    *((int *)t4) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t11 = (t4 + 4);
    *((int *)t11) = 0;
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 16);
    xsi_set_current_line(44, ng0);
    *((int *)t4) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t4 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    xsi_set_current_line(45, ng0);
    t2 = (t0 + 3064);
    xsi_process_wait(t2, 7000LL);
    *((char **)t1) = &&LAB18;
    goto LAB1;

LAB18:    t2 = (t0 + 5288);
    t9 = *((int *)t2);
    *((int *)t2) = (t9 - 1);
    goto LAB14;

LAB19:    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(51, ng0);
    *((int *)t4) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t4 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    xsi_set_current_line(52, ng0);
    t2 = (t0 + 3064);
    xsi_process_wait(t2, 15000LL);
    *((char **)t1) = &&LAB20;
    goto LAB1;

LAB20:    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t2 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (~(t6));
    t8 = *((unsigned int *)t2);
    t9 = (t8 & t7);
    t5 = (t0 + 5292);
    *((int *)t5) = t9;

LAB21:    t10 = (t0 + 5292);
    if (*((int *)t10) > 0)
        goto LAB22;

LAB23:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t10 = (t0 + 1448);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 16);
    xsi_set_current_line(60, ng0);
    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t5 = *((char **)t3);
    t10 = (t0 + 1608);
    xsi_vlogvar_assign_value(t10, t5, 0, 0, 16);
    xsi_set_current_line(61, ng0);
    t2 = (t0 + 3064);
    xsi_process_wait(t2, 25000LL);
    *((char **)t1) = &&LAB26;
    goto LAB1;

LAB22:    xsi_set_current_line(54, ng0);

LAB24:    xsi_set_current_line(55, ng0);
    *((int *)t4) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t11 = (t4 + 4);
    *((int *)t11) = 0;
    t12 = (t0 + 1448);
    xsi_vlogvar_assign_value(t12, t4, 0, 0, 16);
    xsi_set_current_line(56, ng0);
    *((int *)t4) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t4 + 4);
    *((int *)t2) = 0;
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 16);
    xsi_set_current_line(57, ng0);
    t2 = (t0 + 3064);
    xsi_process_wait(t2, 7000LL);
    *((char **)t1) = &&LAB25;
    goto LAB1;

LAB25:    t2 = (t0 + 5292);
    t9 = *((int *)t2);
    *((int *)t2) = (t9 - 1);
    goto LAB21;

LAB26:    goto LAB1;

}


extern void work_m_00000000001517007607_3365466640_init()
{
	static char *pe[] = {(void *)Always_23_0,(void *)Initial_25_1};
	xsi_register_didat("work_m_00000000001517007607_3365466640", "isim/TestQ1_isim_beh.exe.sim/work/m_00000000001517007607_3365466640.didat");
	xsi_register_executes(pe);
}
