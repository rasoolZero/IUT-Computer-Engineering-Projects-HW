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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000002347183893_0347830796_init();
    work_m_00000000000389306428_1736564901_init();
    work_m_00000000003795351551_0845904532_init();
    work_m_00000000000985102747_3045536150_init();
    work_m_00000000001517007607_3365466640_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000001517007607_3365466640");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
