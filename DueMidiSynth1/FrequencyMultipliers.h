#pragma once

const int FrequencyMultiplierScale = 1000;

const int FrequencyMultipliers_4x64[] = {
1000,
1011,
1022,
1033,
1044,
1056,
1067,
1079,
1091,
1102,
1114,
1127,
1139,
1151,
1164,
1176,
1189,
1202,
1215,
1228,
1242,
1255,
1269,
1283,
1297,
1311,
1325,
1340,
1354,
1369,
1384,
1399,
1414,
1430,
1445,
1461,
1477,
1493,
1509,
1526,
1542,
1559,
1576,
1593,
1610,
1628,
1646,
1664,
1682,
1700,
1719,
1737,
1756,
1775,
1795,
1814,
1834,
1854,
1874,
1895,
1915,
1936,
1957,
1978,
2000,
2022,
2044,
2066,
2089,
2111,
2134,
2158,
2181,
2205,
2229,
2253,
2278,
2302,
2327,
2353,
2378,
2404,
2430,
2457,
2484,
2511,
2538,
2566,
2594,
2622,
2650,
2679,
2709,
2738,
2768,
2798,
2828,
2859,
2890,
2922,
2954,
2986,
3018,
3051,
3084,
3118,
3152,
3186,
3221,
3256,
3292,
3327,
3364,
3400,
3437,
3475,
3513,
3551,
3589,
3629,
3668,
3708,
3748,
3789,
3830,
3872,
3914,
3957,
4000,
4044,
4088,
4132,
4177,
4223,
4269,
4315,
4362,
4410,
4458,
4506,
4555,
4605,
4655,
4706,
4757,
4809,
4861,
4914,
4967,
5022,
5076,
5131,
5187,
5244,
5301,
5359,
5417,
5476,
5536,
5596,
5657,
5718,
5781,
5844,
5907,
5972,
6037,
6102,
6169,
6236,
6304,
6373,
6442,
6512,
6583,
6655,
6727,
6800,
6874,
6949,
7025,
7102,
7179,
7257,
7336,
7416,
7497,
7578,
7661,
7744,
7829,
7914,
8000,
8087,
8175,
8264,
8354,
8445,
8537,
8630,
8724,
8819,
8915,
9012,
9110,
9210,
9310,
9411,
9514,
9617,
9722,
9828,
9935,
10043,
10152,
10263,
10375,
10488,
10602,
10717,
10834,
10952,
11071,
11192,
11314,
11437,
11561,
11687,
11815,
11943,
12073,
12205,
12338,
12472,
12608,
12745,
12884,
13024,
13166,
13309,
13454,
13601,
13749,
13899,
14050,
14203,
14358,
14514,
14672,
14832,
14993,
15157,
15322,
15488,
15657,
15828,
16000
};

const int FrequencyMultipliers_4x256_signed[] = {
  250  ,
251 ,
251 ,
252 ,
253 ,
253 ,
254 ,
255 ,
255 ,
256 ,
257 ,
258 ,
258 ,
259 ,
260 ,
260 ,
261 ,
262 ,
262 ,
263 ,
264 ,
265 ,
265 ,
266 ,
267 ,
268 ,
268 ,
269 ,
270 ,
270 ,
271 ,
272 ,
273 ,
273 ,
274 ,
275 ,
276 ,
276 ,
277 ,
278 ,
279 ,
279 ,
280 ,
281 ,
282 ,
282 ,
283 ,
284 ,
285 ,
285 ,
286 ,
287 ,
288 ,
289 ,
289 ,
290 ,
291 ,
292 ,
293 ,
293 ,
294 ,
295 ,
296 ,
296 ,
297 ,
298 ,
299 ,
300 ,
301 ,
301 ,
302 ,
303 ,
304 ,
305 ,
305 ,
306 ,
307 ,
308 ,
309 ,
310 ,
310 ,
311 ,
312 ,
313 ,
314 ,
315 ,
316 ,
316 ,
317 ,
318 ,
319 ,
320 ,
321 ,
322 ,
322 ,
323 ,
324 ,
325 ,
326 ,
327 ,
328 ,
329 ,
330 ,
330 ,
331 ,
332 ,
333 ,
334 ,
335 ,
336 ,
337 ,
338 ,
339 ,
339 ,
340 ,
341 ,
342 ,
343 ,
344 ,
345 ,
346 ,
347 ,
348 ,
349 ,
350 ,
351 ,
352 ,
353 ,
354 ,
355 ,
355 ,
356 ,
357 ,
358 ,
359 ,
360 ,
361 ,
362 ,
363 ,
364 ,
365 ,
366 ,
367 ,
368 ,
369 ,
370 ,
371 ,
372 ,
373 ,
374 ,
375 ,
376 ,
377 ,
378 ,
379 ,
380 ,
381 ,
382 ,
383 ,
385 ,
386 ,
387 ,
388 ,
389 ,
390 ,
391 ,
392 ,
393 ,
394 ,
395 ,
396 ,
397 ,
398 ,
399 ,
400 ,
402 ,
403 ,
404 ,
405 ,
406 ,
407 ,
408 ,
409 ,
410 ,
411 ,
413 ,
414 ,
415 ,
416 ,
417 ,
418 ,
419 ,
420 ,
422 ,
423 ,
424 ,
425 ,
426 ,
427 ,
428 ,
430 ,
431 ,
432 ,
433 ,
434 ,
436 ,
437 ,
438 ,
439 ,
440 ,
441 ,
443 ,
444 ,
445 ,
446 ,
447 ,
449 ,
450 ,
451 ,
452 ,
454 ,
455 ,
456 ,
457 ,
459 ,
460 ,
461 ,
462 ,
463 ,
465 ,
466 ,
467 ,
469 ,
470 ,
471 ,
472 ,
474 ,
475 ,
476 ,
478 ,
479 ,
480 ,
481 ,
483 ,
484 ,
485 ,
487 ,
488 ,
489 ,
491 ,
492 ,
493 ,
495 ,
496 ,
497 ,
499 ,
500 ,
501 ,
503 ,
504 ,
505 ,
507 ,
508 ,
510 ,
511 ,
512 ,
514 ,
515 ,
517 ,
518 ,
519 ,
521 ,
522 ,
524 ,
525 ,
526 ,
528 ,
529 ,
531 ,
532 ,
534 ,
535 ,
536 ,
538 ,
539 ,
541 ,
542 ,
544 ,
545 ,
547 ,
548 ,
550 ,
551 ,
553 ,
554 ,
556 ,
557 ,
559 ,
560 ,
562 ,
563 ,
565 ,
566 ,
568 ,
569 ,
571 ,
572 ,
574 ,
576 ,
577 ,
579 ,
580 ,
582 ,
583 ,
585 ,
587 ,
588 ,
590 ,
591 ,
593 ,
595 ,
596 ,
598 ,
599 ,
601 ,
603 ,
604 ,
606 ,
608 ,
609 ,
611 ,
613 ,
614 ,
616 ,
618 ,
619 ,
621 ,
623 ,
624 ,
626 ,
628 ,
629 ,
631 ,
633 ,
635 ,
636 ,
638 ,
640 ,
641 ,
643 ,
645 ,
647 ,
648 ,
650 ,
652 ,
654 ,
655 ,
657 ,
659 ,
661 ,
663 ,
664 ,
666 ,
668 ,
670 ,
672 ,
673 ,
675 ,
677 ,
679 ,
681 ,
683 ,
685 ,
686 ,
688 ,
690 ,
692 ,
694 ,
696 ,
698 ,
699 ,
701 ,
703 ,
705 ,
707 ,
709 ,
711 ,
713 ,
715 ,
717 ,
719 ,
721 ,
723 ,
725 ,
727 ,
728 ,
730 ,
732 ,
734 ,
736 ,
738 ,
740 ,
742 ,
744 ,
746 ,
748 ,
751 ,
753 ,
755 ,
757 ,
759 ,
761 ,
763 ,
765 ,
767 ,
769 ,
771 ,
773 ,
775 ,
777 ,
780 ,
782 ,
784 ,
786 ,
788 ,
790 ,
792 ,
794 ,
797 ,
799 ,
801 ,
803 ,
805 ,
807 ,
810 ,
812 ,
814 ,
816 ,
818 ,
821 ,
823 ,
825 ,
827 ,
830 ,
832 ,
834 ,
836 ,
839 ,
841 ,
843 ,
845 ,
848 ,
850 ,
852 ,
855 ,
857 ,
859 ,
862 ,
864 ,
866 ,
869 ,
871 ,
873 ,
876 ,
878 ,
881 ,
883 ,
885 ,
888 ,
890 ,
893 ,
895 ,
897 ,
900 ,
902 ,
905 ,
907 ,
910 ,
912 ,
915 ,
917 ,
919 ,
922 ,
924 ,
927 ,
930 ,
932 ,
935 ,
937 ,
940 ,
942 ,
945 ,
947 ,
950 ,
952 ,
955 ,
958 ,
960 ,
963 ,
965 ,
968 ,
971 ,
973 ,
976 ,
979 ,
981 ,
984 ,
987 ,
989 ,
992 ,
995 ,
997 ,
1000  ,
1003  ,
1005  ,
1008  ,
1011  ,
1014  ,
1016  ,
1019  ,
1022  ,
1025  ,
1027  ,
1030  ,
1033  ,
1036  ,
1039  ,
1041  ,
1044  ,
1047  ,
1050  ,
1053  ,
1056  ,
1059  ,
1061  ,
1064  ,
1067  ,
1070  ,
1073  ,
1076  ,
1079  ,
1082  ,
1085  ,
1088  ,
1091  ,
1093  ,
1096  ,
1099  ,
1102  ,
1105  ,
1108  ,
1111  ,
1114  ,
1117  ,
1120  ,
1123  ,
1127  ,
1130  ,
1133  ,
1136  ,
1139  ,
1142  ,
1145  ,
1148  ,
1151  ,
1154  ,
1157  ,
1161  ,
1164  ,
1167  ,
1170  ,
1173  ,
1176  ,
1180  ,
1183  ,
1186  ,
1189  ,
1192  ,
1196  ,
1199  ,
1202  ,
1205  ,
1209  ,
1212  ,
1215  ,
1219  ,
1222  ,
1225  ,
1228  ,
1232  ,
1235  ,
1238  ,
1242  ,
1245  ,
1249  ,
1252  ,
1255  ,
1259  ,
1262  ,
1266  ,
1269  ,
1272  ,
1276  ,
1279  ,
1283  ,
1286  ,
1290  ,
1293  ,
1297  ,
1300  ,
1304  ,
1307  ,
1311  ,
1315  ,
1318  ,
1322  ,
1325  ,
1329  ,
1332  ,
1336  ,
1340  ,
1343  ,
1347  ,
1351  ,
1354  ,
1358  ,
1362  ,
1365  ,
1369  ,
1373  ,
1376  ,
1380  ,
1384  ,
1388  ,
1391  ,
1395  ,
1399  ,
1403  ,
1407  ,
1410  ,
1414  ,
1418  ,
1422  ,
1426  ,
1430  ,
1433  ,
1437  ,
1441  ,
1445  ,
1449  ,
1453  ,
1457  ,
1461  ,
1465  ,
1469  ,
1473  ,
1477  ,
1481  ,
1485  ,
1489  ,
1493  ,
1497  ,
1501  ,
1505  ,
1509  ,
1513  ,
1517  ,
1521  ,
1526  ,
1530  ,
1534  ,
1538  ,
1542  ,
1546  ,
1551  ,
1555  ,
1559  ,
1563  ,
1567  ,
1572  ,
1576  ,
1580  ,
1585  ,
1589  ,
1593  ,
1597  ,
1602  ,
1606  ,
1610  ,
1615  ,
1619  ,
1624  ,
1628  ,
1632  ,
1637  ,
1641  ,
1646  ,
1650  ,
1655  ,
1659  ,
1664  ,
1668  ,
1673  ,
1677  ,
1682  ,
1686  ,
1691  ,
1696  ,
1700  ,
1705  ,
1709  ,
1714  ,
1719  ,
1723  ,
1728  ,
1733  ,
1737  ,
1742  ,
1747  ,
1752  ,
1756  ,
1761  ,
1766  ,
1771  ,
1775  ,
1780  ,
1785  ,
1790  ,
1795  ,
1800  ,
1804  ,
1809  ,
1814  ,
1819  ,
1824  ,
1829  ,
1834  ,
1839  ,
1844  ,
1849  ,
1854  ,
1859  ,
1864  ,
1869  ,
1874  ,
1879  ,
1884  ,
1889  ,
1895  ,
1900  ,
1905  ,
1910  ,
1915  ,
1920  ,
1926  ,
1931  ,
1936  ,
1941  ,
1947  ,
1952  ,
1957  ,
1962  ,
1968  ,
1973  ,
1978  ,
1984  ,
1989  ,
1995  ,
2000  ,
2005  ,
2011  ,
2016  ,
2022  ,
2027  ,
2033  ,
2038  ,
2044  ,
2049  ,
2055  ,
2060  ,
2066  ,
2072  ,
2077  ,
2083  ,
2089  ,
2094  ,
2100  ,
2106  ,
2111  ,
2117  ,
2123  ,
2129  ,
2134  ,
2140  ,
2146  ,
2152  ,
2158  ,
2163  ,
2169  ,
2175  ,
2181  ,
2187  ,
2193  ,
2199  ,
2205  ,
2211  ,
2217  ,
2223  ,
2229  ,
2235  ,
2241  ,
2247  ,
2253  ,
2259  ,
2265  ,
2271  ,
2278  ,
2284  ,
2290  ,
2296  ,
2302  ,
2309  ,
2315  ,
2321  ,
2327  ,
2334  ,
2340  ,
2346  ,
2353  ,
2359  ,
2366  ,
2372  ,
2378  ,
2385  ,
2391  ,
2398  ,
2404  ,
2411  ,
2417  ,
2424  ,
2430  ,
2437  ,
2444  ,
2450  ,
2457  ,
2464  ,
2470  ,
2477  ,
2484  ,
2490  ,
2497  ,
2504  ,
2511  ,
2518  ,
2524  ,
2531  ,
2538  ,
2545  ,
2552  ,
2559  ,
2566  ,
2573  ,
2580  ,
2587  ,
2594  ,
2601  ,
2608  ,
2615  ,
2622  ,
2629  ,
2636  ,
2643  ,
2650  ,
2658  ,
2665  ,
2672  ,
2679  ,
2687  ,
2694  ,
2701  ,
2709  ,
2716  ,
2723  ,
2731  ,
2738  ,
2745  ,
2753  ,
2760  ,
2768  ,
2775  ,
2783  ,
2790  ,
2798  ,
2806  ,
2813  ,
2821  ,
2828  ,
2836  ,
2844  ,
2851  ,
2859  ,
2867  ,
2875  ,
2883  ,
2890  ,
2898  ,
2906  ,
2914  ,
2922  ,
2930  ,
2938  ,
2946  ,
2954  ,
2962  ,
2970  ,
2978  ,
2986  ,
2994  ,
3002  ,
3010  ,
3018  ,
3027  ,
3035  ,
3043  ,
3051  ,
3059  ,
3068  ,
3076  ,
3084  ,
3093  ,
3101  ,
3110  ,
3118  ,
3126  ,
3135  ,
3143  ,
3152  ,
3161  ,
3169  ,
3178  ,
3186  ,
3195  ,
3204  ,
3212  ,
3221  ,
3230  ,
3238  ,
3247  ,
3256  ,
3265  ,
3274  ,
3283  ,
3292  ,
3300  ,
3309  ,
3318  ,
3327  ,
3336  ,
3345  ,
3354  ,
3364  ,
3373  ,
3382  ,
3391  ,
3400  ,
3409  ,
3419  ,
3428  ,
3437  ,
3447  ,
3456  ,
3465  ,
3475  ,
3484  ,
3494  ,
3503  ,
3513  ,
3522  ,
3532  ,
3541  ,
3551  ,
3560  ,
3570  ,
3580  ,
3589  ,
3599  ,
3609  ,
3619  ,
3629  ,
3638  ,
3648  ,
3658  ,
3668  ,
3678  ,
3688  ,
3698  ,
3708  ,
3718  ,
3728  ,
3738  ,
3748  ,
3758  ,
3769  ,
3779  ,
3789  ,
3799  ,
3810  ,
3820  ,
3830  ,
3841  ,
3851  ,
3862  ,
3872  ,
3883  ,
3893  ,
3904  ,
3914  ,
3925  ,
3936  ,
3946  ,
3957  ,
3968  ,
3978  ,
3989  ,
4000
};
