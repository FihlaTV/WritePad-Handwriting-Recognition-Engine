/***************************************************************************************
 *
 *  WRITEPAD(r): Handwriting Recognition Engine (HWRE) and components.
 *  Copyright (c) 2001-2016 PhatWare (r) Corp. All rights reserved.
 *
 *  Licensing and other inquires: <developer@phatware.com>
 *  Developer: Stan Miasnikov, et al. (c) PhatWare Corp. <http://www.phatware.com>
 *
 *  WRITEPAD HWRE is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
 *  AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 *  INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 *  FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL PHATWARE CORP.
 *  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT, SPECIAL, INCIDENTAL,
 *  INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER,
 *  INCLUDING WITHOUT LIMITATION, LOSS OF PROFIT, LOSS OF USE, SAVINGS
 *  OR REVENUE, OR THE CLAIMS OF THIRD PARTIES, WHETHER OR NOT PHATWARE CORP.
 *  HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
 *  POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
 *  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with WritePad.  If not, see <http://www.gnu.org/licenses/>.
 *
 **************************************************************************************/

#pragma once

// Autocorrector list for German recognizer

static const char * g_szDefWords_GER[] = {
	"abeiten",	"arbeiten",
	"Abnachung",	"Abmachung",
	"Accesoir",	"Accessoire",
	"Acksessoir",	"Accessoire",
	"adnere",	"andere",
	"adneren",	"anderen",
	"adneres",	"anderes",
	"adners",	"anders",
	"Aksessoir",	"Accessoire",
	"aler",	"aller",
	"anderne",	"andere",
	"arbete",	"arbeite",
	"arbeten",	"arbeiten",
	"arbetest",	"arbeitest",
	"arbetet",	"arbeitet",
	"Argumnet",	"Argument",
	"Assessoir",	"Accessoire",
	"auslandisch",	"ausl\xe4ndisch",
	"Auswal",	"Auswahl",
	"beerits",	"bereits",
	"befor",	"bevor",
	"bekant",	"bekannt",
	"Bekante",	"Bekannte",
	"Bekanter",	"Bekannter",
	"bekantes",	"bekanntes",
	"Bel\xe4stignug",	"Bel\xe4stigung",
	"Bel\xe4tsigung",	"Bel\xe4stigung",
	"bereis",	"bereits",
	"Bescherde",	"Beschwerde",
	"besc\xe4men",	"besch\xe4men",
	"Bibliotekh",	"Bibliothek",
	"Bibliothrk",	"Bibliothek",
	"Bl\xe4stigung",	"Bel\xe4stigung",
	"brauchenicht",	"brauche nicht",
	"brauchstnicht",	"brauchst nicht",
	"brauchtnicht",	"braucht nicht",
	"Buchsabe",	"Buchstabe",
	"Buchstbae",	"Buchstabe",
	"dachet",	"dachte",
	"darfnicht",	"darf nicht",
	"darfstnicht",	"darfst nicht",
	"daselbe",	"dasselbe",
	"Datein",	"Dateien",
	"dei",	"die",
	"deis",	"dies",
	"deise",	"diese",
	"deiser",	"dieser",
	"dekne",	"denke",
	"deknst",	"denkst",
	"dersselbe",	"derselbe",
	"diesre",	"dieser",
	"diesselbe",	"dieselbe",
	"dirr",	"dir",
	"dise",	"diese",
	"disees",	"dieses",
	"diser",	"dieser",
	"Dnak",	"Dank",
	"dnake",	"danke",
	"Dockument",	"Dokument",
	"Dokkument",	"Dokument",
	"Dokumnet",	"Dokument",
	"dubist",	"du bist",
	"d\xfcrfennicht",	"d\xfcrfen nicht",
	"edr",	"der",
	"ehielt",	"erhielt",
	"emfehlen",	"empfehlen",
	"empfelen",	"empfehlen",
	"empfelhen",	"empfehlen",
	"enige",	"einige",
	"eniges",	"einiges",
	"enldich",	"endlich",
	"Entwicklug",	"Entwicklung",
	"Enwicklung",	"Entwicklung",
	"ereichen",	"erreichen",
	"ereicht",	"erreicht",
	"Erflg",	"Erfolg",
	"erhalen",	"erhalten",
	"erhaltn",	"erhalten",
	"erhlaten",	"erhalten",
	"erinern",	"erinnern",
	"erkennn",	"erkennen",
	"erknennen",	"erkennen",
	"erts",	"erst",
	"fandn",	"fanden",
	"fiden",	"finden",
	"findn",	"finden",
	"Firna",	"Firma",
	"fnad",	"fand",
	"fnaden",	"fanden",
	"fnadst",	"fandst",
	"Fnester",	"Fenster",
	"folgn",	"folgen",
	"folgnd",	"folgend",
	"follgen",	"folgen",
	"follgend",	"folgend",
	"follgende",	"folgende",
	"follgender",	"folgender",
	"follgendes",	"folgendes",
	"Forfall",	"Vorfall",
	"fpr",	"f\xfcr",
	"fur",	"f\xfcr",
	"Fra",	"Frau",
	"Fraeg",	"Frage",
	"fragn",	"fragen",
	"Freudne",	"Freunde",
	"Freundinen",	"Freundinnen",
	"Frima",	"Firma",
	"Fru",	"Frau",
	"fsat",	"fast",
	"f\xe4\xf6schlich",	"f\xe4lschlich",
	"Garanti",	"Garantie",
	"Garrantie",	"Garantie",
	"Gechichte",	"Geschichte",
	"Gecshichte",	"Geschichte",
	"Gefar",	"Gefahr",
	"gehn",	"gehen",
	"gehts",	"geht's",
	"Geidcht",	"Gedicht",
	"Gelegenhet",	"Gelegenheit",
	"Gelgenheit",	"Gelegenheit",
	"geradde",	"gerade",
	"Geschichtne",	"Geschichten",
	"Geshichte",	"Geschichte",
	"ghe",	"gehe",
	"ghen",	"gehen",
	"ghest",	"gehst",
	"gibts",	"gibt's",
	"glaben",	"glauben",
	"glaubn",	"glauben",
	"gnaz",	"ganz",
	"Grupe",	"Gruppe",
	"gschehen",	"geschehen",
	"habenicht",	"habe nicht",
	"habn",	"haben",
	"haett",	"hatte",
	"hastnicht",	"hast nicht",
	"hatnicht",	"hat nicht",
	"hbe",	"habe",
	"hoffendlich",	"hoffentlich", 
	"hst",	"hast",
	"ht",	"hat",
	"Htp",	"http",
	"Http",	"http",
	"http:11",	"http://",
	"Http:\\\\",	"http://",
	"huete",	"heute",
	"Hypotek",	"Hypothek",
	"ienes",	"eines",
	"ienige",	"einige",
	"ieniges",	"einiges",
	"ieronisch",	"ironisch",
	"ih",	"ich",
	"ihc",	"ich",
	"imer",	"immer",
	"inRichtung",	"in Richtung",
	"Intriege",	"Intrige",
	"intriegieren",	"intrigieren",
	"Intrife",	"Intrige",
	"ires",	"ihres",
	"its",	"ist",
	"Jare",	"Jahre",
	"jettz",	"jetzt",
	"jezt",	"jetzt",
	"Jhar",	"Jahr",
	"kalrer",	"klarer",
	"kan",	"kann",
	"kannicht",	"kann nicht",
	"kannnicht",	"kann nicht",
	"kien",	"kein",
	"kiene",	"keine",
	"kienes",	"keines",
	"kiense",	"keines",
	"klin",	"klein",
	"klint",	"klingt",
	"klnnen",	"k\xf6nnen",
	"klr",	"klar",
	"klra",	"klar",
	"kna",	"kann",
	"Komite",	"Komitee",
	"Komittee",	"Komitee",
	"Kommitee",	"Komitee",
	"Kommittee",	"Komitee",
	"Kompre\xdfion",	"Kompression",
	"komunizieren",	"kommunizieren",
	"konte",	"konnte",
	"koonte",	"konnte",
	"Kopei",	"Kopie",
	"Kres",	"Kreis",
	"k\xf6nte",	"k\xf6nnte",
	"Labaratorium",	"Laboratorium",
	"Labbor",	"Labor",
	"Labohratorium",	"Laboratorium",
	"lebn",	"leben",
	"Leistnug",	"Leistung",
	"Leistug",	"Leistung",
	"Leisung",	"Leistung",
	"Lestung",	"Leistung",
	"Libe",	"Liebe",
	"Liestung",	"Leistung",
	"Lizentz",	"Lizenz",
	"Luete",	"Leute",
	"macen",	"machen",
	"machn",	"machen",
	"macst",	"machst",
	"Mact",	"Macht",
	"macte",	"machte",
	"magts",	"magst",
	"Mathemaitk",	"Mathematik",
	"Mathematikk",	"Mathematik",
	"Mathemetik",	"Mathematik",
	"Mathrmatik",	"Mathematik",
	"Mattematik",	"Mathematik",
	"mene",	"meine",
	"Mesnchen",	"Menschen",
	"mfg",	"Mit freundlichen Gr\xfc\xdf\x65n",
	"michselbst",	"mich selbst",
	"mirselbst",	"mir selbst",
	"mocte",	"mochte",
	"m\xf6\x63ht",	"m\xf6\x63hte",
	"nachste",	"n\xe4\x63hste",
	"nachster",	"n\xe4\x63hster",
	"nachstes",	"n\xe4\x63hstes",
	"nciht",	"nicht",
	"nehmem",	"nehmen",
	"nemen",	"nehmen",
	"Nihcte",	"Nichte",
	"nimst",	"nimmst",
	"nltig",	"n\xf6tig",
	"Nunner",	"Nummer",
	"nurr",	"nur",
	"n\xe4hmlich",	"n\xe4mlich",
	"n\xe4tig",	"n\xf6tig",
	"N\xf6rigung",	"N\xf6tigung",
	"oaky",	"okay",
	"ofenbar",	"offenbar",
	"ofensichtlich",	"offensichtlich",
	"offensicgtlich",	"offensichtlich",
	"offensichylich",	"offensichtlich",
	"uber",	"\xfc\x62\x65r",
	"pber",	"\xfc\x62\x65r",
	"pbertreiben",	"\xfc\x62\x65rtreiben",
	"Piknick",	"Picknick",
	"Piknik",	"Picknick",
	"Porblem",	"Problem",
	"Porzelan",	"Porzellan",
	"Porzellam",	"Porzellan",
	"Porzellna",	"Porzellan",
	"Potzellan",	"Porzellan",
	"Prioit\xe4t",	"Priorit\xe4t",
	"priorit\xe4t",	"Priorit\xe4t",
	"Problen",	"Problem",
	"Prozellan",	"Porzellan",
	"Psycgologie",	"Psychologie",
	"Rechnug",	"Rechnung",
	"ipad"			  "iPad",
	"ipod"			  "iPod",
	"iphone",		  "iPhone",
	"Rekrod",	"Rekord",
	"Rhytmus",	"Rhythmus",
	"Rythmus",	"Rhythmus",
	"Rytmus",	"Rhythmus",
	"Sachem",	"Sachen",
	"Sahce",	"Sache",
	"schonn",	"schon",
	"schrebe",	"schreibe",
	"schrebst",	"schreibst",
	"schreibn",	"schreiben",
	"schriben",	"schreiben",
	"scon",	"schon",
	"Seckret\xe4rin",	"Sekret\xe4rin",
	"seinse",	"seines",
	"Sekret\xe4tin",	"Sekret\xe4rin",
	"seperat",	"separat",
	"seteht",	"steht",
	"sgdh",	"Sehr geehrte Damen und Herren",
	"sichausdenken",	"sich ausdenken",
	"sien",	"sein",
	"siene",	"seine",
	"sienem",	"seinem",
	"sienes",	"seines",
	"sioe",	"sie",
	"slebst",	"selbst",
	"solltenicht",	"sollte nicht",
	"solltennicht",	"sollten nicht",
	"solltestnicht",	"solltest nicht",
	"solte",	"sollte",
	"solten",	"sollten",
	"soltest",	"solltest",
	"sparch",	"sprach",
	"spircht",	"spricht",
	"sprechn",	"sprechen",
	"sprischt",	"sprichst",
	"steen",	"stehen",
	"stpo",	"stopp",
	"St\xe4rkke",	"St\xe4rke",
	"synon\xfcm",	"synonym",
	"s\xfcnonym",	"synonym",
	"s\xfcnon\xfcm",	"synonym",
	"tirnkst",	"trinkst",
	"Traume",	"Tr\xe4ume",
	"trinkn",	"trinken",
	"trint",	"trinkt",
	"t\xe4usvhen",	"t\xe4uschen",
	"umbedingt",	"unbedingt",
	"Unabh\xe4gnigkeit",	"Unabh\xe4ngigkeit",
	"Unabh\xe4ngigket",	"Unabh\xe4ngigkeit",
	"Unahangigkeit",	"Unabh\xe4ngigkeit",
	"unbdingt",	"unbedingt",
	"unbedinkt",	"unbedingt",
	"unbedint",	"unbedingt",
	"unddas",	"und das",
	"undder",	"und der",
	"unddie",	"und die",
	"unrerbringen",	"unterbringen",
	"unterbingen",	"unterbringen",
	"Unterbingung",	"Unterbringung",
	"Unterbrignug",	"Unterbringung",
	"unzufriden",	"unzufrieden",
	"uz",	"zu",
	"veilleicht",	"vielleicht",
	"Versamlung",	"Versammlung",
	"vieleicht",	"vielleicht",
	"Vorang",	"Vorrang",
	"Vorfal",	"Vorfall",
	"Vorvall",	"Vorfall",
	"vuchstabieren",	"buchstabieren",
	"wachesn",	"wachsen",
	"wasist",	"was ist",
	"wechle",	"welche",
	"wechler",	"welcher",
	"wechles",	"welches",
	"wedre",	"werde",
	"weider",	"wieder",
	"weisst",	"wei\xdft",
	"weng",	"wenig",
	"wenge",	"wenige",
	"werd",	"wird",
	"Widnows",	"Windows",
	"wiederschreiben",	"wieder schreiben",
	"wiel",	"weil",
	"wie\xdf",	"wei\xdf",
	"wie\xdf\x65",	"wei\xdf\x65",
	"wie\xdft",	"wei\xdft",
	"wiklich",	"wirklich",
	"wil",	"will",
	"wilst",	"willst",
	"wirds",	"wird's",
	"wisen",	"wissen",
	"wissn",	"wissen",
	"wolen",	"wollen",
	"wolltn",	"wollten",
	"wolte",	"wollte",
	"wolten",	"wollten",
	"woltest",	"wolltest",
	"woolten",	"wollten",
	"wriklich",	"wirklich",
	"wriklih",	"wirklich",
	"Wrot",	"Wort",
	"w\xfc\x64re",	"w\xfcrde",
	"w\xfc\x64ren",	"w\xfcrden",
	"w\xfcrdst",	"w\xfcrdest",
	"zeigem",	"zeigen",
	"Zeti",	"Zeit",
	"Zite",	"Zeit",
	"Zuhschauer",	"Zuschauer",
	"Zuh\xe4rer",	"Zuh\xf6rer",
	"zuruck",	"zur\xfc\x63k",
	"z\xfcr\xfc\x63k",	"zur\xfc\x63k",
	"\xe4nlich",	"\xe4hnlich",
	"\xfc\x62\x65rtreibn",	"\xfc\x62\x65rtreiben",
	"\xfc\x62\x65trreiben",	"\xfc\x62\x65rtreiben",
	"\xfchnlich",	"\xe4hnlich",
};

#define DEFWORDCNT_GER  (sizeof(g_szDefWords_GER)/sizeof(g_szDefWords_GER[0]))
