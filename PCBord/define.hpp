#ifndef DEFINE
#define DEFINE
#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <thread>
#include <math.h>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "json.hpp"

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

using namespace sf;
using namespace std;
using namespace std::literals::chrono_literals;
using json = nlohmann::json;

#define V2f sf::Vector2f
#define V2i sf::Vector2i
#define PI 3.14159265
#define Constant_G 9.81
#define TMAJ 15

#define DARK_BLUE Color(3,17,34)
#define SHADOW Color(8,24,57)
#define BLACK Color(0,0,0)
#define WHITE Color(255,255,255)
#define RED Color(191,0,2)
#define ORANGE Color(234,145,0)
#define GREEN Color(68,255,0)
#define YELLOW Color(223,223,0)
#define PASP_DARK Color(33,49,74)
#define PASP_LIGHT Color(41,74,107)
#define GREY Color(195,195,195)
#define MEDIUM_GREY Color(150,150,150)
#define DARK_GREY Color(85,85,85)

#define DR_01 (*symbol)[0]
#define DR_02 (*symbol)[1]
#define DR_03 (*symbol)[2]
#define DR_04 (*symbol)[3]
#define DR_05 (*symbol)[4]
#define LE_01 (*symbol)[5]
#define LE_02 (*symbol)[6]
#define LE_02a (*symbol)[7]
#define LE_03 (*symbol)[8]
#define LE_04 (*symbol)[9]
#define LE_05 (*symbol)[10]
#define LE_06 (*symbol)[11]
#define LE_07 (*symbol)[12]
#define LE_08 (*symbol)[13]
#define LE_08a (*symbol)[14]
#define LE_09 (*symbol)[15]
#define LE_09a (*symbol)[16]
#define LE_10 (*symbol)[17]
#define LE_11 (*symbol)[18]
#define LE_12 (*symbol)[19]
#define LE_13 (*symbol)[20]
#define LE_14 (*symbol)[21]
#define LE_15 (*symbol)[22]
#define LS_01 (*symbol)[23]
#define LX_01 (*symbol)[24]
#define MO_01 (*symbol)[25]
#define MO_02 (*symbol)[26]
#define MO_03 (*symbol)[27]
#define MO_04 (*symbol)[28]
#define MO_05 (*symbol)[29]
#define MO_06 (*symbol)[30]
#define MO_07 (*symbol)[31]
#define MO_08 (*symbol)[32]
#define MO_09 (*symbol)[33]
#define MO_10 (*symbol)[34]
#define MO_11 (*symbol)[35]
#define MO_12 (*symbol)[36]
#define MO_13 (*symbol)[37]
#define MO_14 (*symbol)[38]
#define MO_15 (*symbol)[39]
#define MO_16 (*symbol)[40]
#define MO_17 (*symbol)[41]
#define MO_18 (*symbol)[42]
#define MO_19 (*symbol)[43]
#define MO_20 (*symbol)[44]
#define MO_21 (*symbol)[45]
#define MO_22 (*symbol)[46]
#define NA_01 (*symbol)[47]
#define NA_02 (*symbol)[48]
#define NA_03 (*symbol)[49]
#define NA_04 (*symbol)[50]
#define NA_05 (*symbol)[51]
#define NA_06 (*symbol)[52]
#define NA_07 (*symbol)[53]
#define NA_08 (*symbol)[54]
#define NA_09 (*symbol)[55]
#define NA_10 (*symbol)[56]
#define NA_11 (*symbol)[57]
#define NA_12 (*symbol)[58]
#define NA_13 (*symbol)[59]
#define NA_14 (*symbol)[60]
#define NA_15 (*symbol)[61]
#define NA_16 (*symbol)[62]
#define NA_17 (*symbol)[63]
#define NA_18 (*symbol)[64]
#define NA_18_2 (*symbol)[65]
#define NA_19 (*symbol)[66]
#define NA_20 (*symbol)[67]
#define NA_21 (*symbol)[68]
#define NA_22 (*symbol)[69]
#define NA_23 (*symbol)[70]
#define PL_01 (*symbol)[71]
#define PL_02 (*symbol)[72]
#define PL_03 (*symbol)[73]
#define PL_04 (*symbol)[74]
#define PL_05 (*symbol)[75]
#define PL_06 (*symbol)[76]
#define PL_07 (*symbol)[77]
#define PL_08 (*symbol)[78]
#define PL_09 (*symbol)[79]
#define PL_10 (*symbol)[80]
#define PL_11 (*symbol)[81]
#define PL_12 (*symbol)[82]
#define PL_13 (*symbol)[83]
#define PL_14 (*symbol)[84]
#define PL_15 (*symbol)[85]
#define PL_16 (*symbol)[86]
#define PL_17 (*symbol)[87]
#define PL_18 (*symbol)[88]
#define PL_19 (*symbol)[89]
#define PL_20 (*symbol)[90]
#define PL_21 (*symbol)[91]
#define PL_22 (*symbol)[92]
#define PL_23 (*symbol)[93]
#define PL_24 (*symbol)[94]
#define PL_25 (*symbol)[95]
#define PL_26 (*symbol)[96]
#define PL_27 (*symbol)[97]
#define PL_28 (*symbol)[98]
#define PL_29 (*symbol)[99]
#define PL_30 (*symbol)[100]
#define PL_31 (*symbol)[101]
#define PL_32 (*symbol)[102]
#define PL_33 (*symbol)[103]
#define PL_34 (*symbol)[104]
#define PL_35 (*symbol)[105]
#define PL_36 (*symbol)[106]
#define SE_01 (*symbol)[107]
#define SE_02 (*symbol)[108]
#define SE_03 (*symbol)[109]
#define SE_04 (*symbol)[110]
#define ST_01 (*symbol)[111]
#define ST_02 (*symbol)[112]
#define ST_03 (*symbol)[113]
#define ST_04 (*symbol)[114]
#define ST_05 (*symbol)[115]
#define ST_06 (*symbol)[116]
#define TC_01 (*symbol)[117]
#define TC_02 (*symbol)[118]
#define TC_03 (*symbol)[119]
#define TC_04 (*symbol)[120]
#define TC_05 (*symbol)[121]
#define TC_06 (*symbol)[122]
#define TC_07 (*symbol)[123]
#define TC_08 (*symbol)[124]
#define TC_09 (*symbol)[125]
#define TC_10 (*symbol)[126]
#define TC_11 (*symbol)[127]
#define TC_12 (*symbol)[128]
#define TC_13 (*symbol)[129]
#define TC_14 (*symbol)[130]
#define TC_15 (*symbol)[131]
#define TC_16 (*symbol)[132]
#define TC_17 (*symbol)[133]
#define TC_18 (*symbol)[134]
#define TC_19 (*symbol)[135]
#define TC_20 (*symbol)[136]
#define TC_21 (*symbol)[137]
#define TC_22 (*symbol)[138]
#define TC_23 (*symbol)[139]
#define TC_24 (*symbol)[140]
#define TC_25 (*symbol)[141]
#define TC_26 (*symbol)[142]
#define TC_27 (*symbol)[143]
#define TC_28 (*symbol)[144]
#define TC_29 (*symbol)[145]
#define TC_30 (*symbol)[146]
#define TC_31 (*symbol)[147]
#define TC_32 (*symbol)[148]
#define TC_33 (*symbol)[149]
#define TC_34 (*symbol)[150]
#define TC_35 (*symbol)[151]
#define TC_36 (*symbol)[152]
#define TC_37 (*symbol)[153]
#define Sect (*symbol)[154]
#define BP (*symbol)[155]
#endif