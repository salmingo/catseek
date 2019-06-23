/*
 Name        : catseek.cpp
 Author      : Xiaomeng Lu
 Version     : 0.1
 Copyright   : SVOM@NAOC, CAS
 Description : 搜索星表, 输出复合条件的参考星
 - 搜索UCAC4星表, 若找到则输出信息; 未找到继续
 - 搜索Tycho2星表, 若找到则输出信息
 */

#include <stdio.h>
#include <string>
#include "ATimeSpace.h"
#include "ACatUCAC4.h"

using namespace std;
using namespace AstroUtil;

/*
 * 命令行输入参数:
 * <1> 赤经. 角度
 * <2> 赤纬. 角度
 * <3> 半径, 量纲: 角分. 缺省时为1
 */
int main(int argc, char **argv) {
	if (argc < 3) {
		printf("%s\n", string('*', 60).c_str());
		printf("Usage:\n");
		printf("\t catseek ra dec [radius=1]\n");
		printf("%s\n", string('*', 60).c_str());
		exit(-1);
	}

	double ra0, dec0, radius(1.0);
	double ra, dec;
	ACatUCAC4 ucac4;
	ATimeSpace ats;
	int n, i;

	ucac4.SetPathRoot("/Users/lxm/Catalogue/UCAC4");

	ra0 = atof(argv[1]);
	dec0 = atof(argv[2]);
	if (argc == 4)
		radius = atof(argv[3]);

	if (ucac4.FindStar(ra0, dec0, radius)) {
		ptr_ucac4_elem stars, star;

		stars = ucac4.GetResult(n);
		printf("%12s  %12s  %7s  %7s  %6s  %6s  %6s  %6s\n", "RA     ",
				"DEC    ", "pmRA  ", "pmDEC ", "B  ", "V  ", "g  ", "r  ");
		printf("%s\n", string(78, '-').c_str());
		for (i = 0, star = stars; i < n; ++i, ++star) {
			ra = (double) star->ra / MILLISEC;
			dec = (double) star->spd / MILLISEC - 90.0;
			printf("%12.8f  %12.8f  %7.1f  %7.1f  %6.3f  %6.3f  %6.3f  %6.3f\n",
					ra, dec, star->pmrac * 0.1, star->pmdc * 0.1,
					star->apasm[0] * 0.001, star->apasm[1] * 0.001,
					star->apasm[2] * 0.001, star->apasm[3] * 0.001);
		}
	}

	return 0;
}
