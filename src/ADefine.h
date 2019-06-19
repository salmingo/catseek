/*
 * @file astro_common.h 天文常数及宏定义
 */

#ifndef ADEFINE_H_
#define ADEFINE_H_

#include <math.h>

namespace AstroUtil {
/*--------------------------------------------------------------------------*/
// 平面角转换系数
#define API		3.141592653589793238462643		//< 圆周率
#define A2PI	6.283185307179586476925287		//< 2倍圆周率
#define R2D		5.729577951308232087679815E1	//< 弧度转换为角度
#define D2R		1.745329251994329576923691E-2	//< 角度转换为弧度
#define R2AS	2.062648062470963551564734E5	//< 弧度转换为角秒
#define AS2R	4.848136811095359935899141E-6	//< 角秒转换为弧度
#define H2D		15.0							//< 小时转换为角度
#define D2H		6.666666666666666666666667E-2	//< 角度转换为小时
#define H2R		2.617993877991494365385536E-1	//< 小时转换为弧度
#define R2H		3.819718634205488058453210		//< 弧度转换为小时
#define S2R		7.272205216643039903848712E-5	//< 秒转换为弧度
#define R2S		1.375098708313975701043156E4	//< 弧度转换为秒
#define D2AS	3600.0							//< 角度转换为角秒
#define AS2D	2.777777777777777777777778E-4	//< 角秒转换为角度
#define MILLISEC		3600000			// 1度对应的毫角秒
#define MILLISEC5		18000000		// 5度对应的毫角秒
#define MILLISEC90		324000000		// 90度对应的毫角秒
#define MILLISEC180		648000000		// 180度对应的毫角秒
#define MILLISEC360		1296000000		// 360度对应的毫角秒

// 时间转换常数
#define JD2K		2451545.0	//< 历元2000对应的儒略日
#define MJD0		2400000.5	//< 修正儒略日零点所对应的儒略日
#define MJD2K		51544.5		//< 历元2000对应的修正儒略日
#define MJD77		43144.0		//< 1977年1月1日0时对应的修正儒略日
#define TTMTAI		32.184		//< TTMTAI=TT-TAI
#define DAYS_JY		365.25		//< 儒略历每年天数
#define DAYS_JC		36525.0		//< 儒略历每世纪天数
#define DAYS_JM		365250.0	//< 儒略历每千年天数
#define DAYSEC		86400.0		//< 每日秒数

// 极限阈值
#define AEPS	1E-6			//< 最小值
#define AMAX	1E30			//< 最大值

// 计算正割函数
#define sec(x)			(1.0 / cos(x))
// 计算实数的小数部分
#define frac(x)			((x) - floor(x))
// 调整到[0, T)周期内
#define cyclemod(x, T)	((x) - floor((x) / (T)) * (T))
/*--------------------------------------------------------------------------*/
}

#endif /* ADEFINE_H_ */
