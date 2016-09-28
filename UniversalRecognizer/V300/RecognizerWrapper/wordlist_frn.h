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


// Autocorrector list for French recognizer

static const char *  g_szDefWords_FRN[] = {
	"abcisse",	"abscisse",
	"absisse",	"abscisse",
	"acalmie",	"accalmie",
	"accompte",	"acompte",
	"accordeon",	"accord\xe9on",
	"accummuler",	"accumuler",
	"acroc",	"accroc",
	"acr\xe9\x64itif",	"accr\xe9\x64itif",
	"afaires",	"affaires",
	"afiliation",	"affiliation",
	"afirmer",	"affirmer",
	"aggio",	"agio",
	"aggios",	"agios",
	"agr\xe8\x65r",	"agr\xe9\x65r",
	"aler",	"aller",
	"allemagne",	"Allemagne",
	"allieurs",	"ailleurs",
	"alocation",	"allocation",
	"alocations",	"allocations",
	"amorticement",	"amortissement",
	"annn\xe9\x65",	"ann\xe9\x65",
	"annuller",	"annuler",
	"anonces",	"annonces",
	"anotation",	"annotation",
	"anotations",	"annotations",
	"antologie",	"anthologie",
	"anuller",	"annuler",
	"an\xe9\x65",	"ann\xe9\x65",
	"an\xe9\x65s",	"ann\xe9\x65s",
	"apareil",	"appareil",
	"apel",	"appel",
	"apels",	"appels",
	"apliquer",	"appliquer",
	"apointements",	"appointements",
	"appeller",	"appeler",
	"appercevoir",	"apercevoir",
	"applciation",	"application",
	"aprendre",	"apprendre",
	"apr\xe8sce",	"apr\xe8s ce",
	"apr\xe8sces",	"apr\xe8s ces",
	"apr\xe8scet",	"apr\xe8s cet",
	"apr\xe8scette",	"apr\xe8s cette",
	"apr\xe8sdes",	"apr\xe8s des",
	"apr\xe8sla",	"apr\xe8s la",
	"apr\xe8sle",	"apr\xe8s le",
	"apr\xe8sles",	"apr\xe8s les",
	"apr\xe8sun",	"apr\xe8s un",
	"apr\xe8sune",	"apr\xe8s une",
	"apr\xe8sce",	"apr\xe8s ce",
	"apr\xe8sces",	"apr\xe8s ces",
	"apr\xe8scet",	"apr\xe8s cet",
	"apr\xe8scette",	"apr\xe8s cette",
	"apr\xe8sdes",	"apr\xe8s des",
	"apr\xe8sla",	"apr\xe8s la",
	"apr\xe8sle",	"apr\xe8s le",
	"apr\xe8sles",	"apr\xe8s les",
	"apr\xe8sun",	"apr\xe8s un",
	"apr\xe8sune",	"apr\xe8s une",
	"apr\xe9\x63ie",	"appr\xe9\x63ie",
	"apr\xe9\x63ier",	"appr\xe9\x63ier",
	"apr\xe9\x63ies",	"appr\xe9\x63ies",
	"apr\xe9s",	"apr\xe8s",
	"aritm\xe9tique",	"arithm\xe9tique",
	"arondissement",	"arrondissement",
	"arondissements",	"arrondissements",
	"artiset",	"artiste",
	"artisets",	"artistes",
	"artisna",	"artisan",
	"artisnas",	"artisans",
	"arute",	"autre",
	"astu",	"as-tu",
	"asociation",	"association",
	"asociations",	"associations",
	"asurance",	"assurance",
	"ateindre",	"atteindre",
	"atestation",	"attestation",
	"atrapper",	"attraper",
	"audel\xe0",	"au-del\xe0",
	"aujourdhiu",	"aujourd'hui",
	"aurontelles",	"auront-elles",
	"aurontils",	"auront-ils",
	"ausi",	"aussi",
	"aussitot",	"aussit\xf4t",
	"autentique",	"authentique",
	"autentiques",	"authentiques",
	"authorisation",	"autorisation",
	"autorization",	"autorisation",
	"autriche",	"Autriche",
	"bacalaur\xe9\x61t",	"baccalaur\xe9\x61t",
	"barage",	"barrage",
	"baucoup",	"beaucoup",
	"belgique",	"Belgique",
	"bibliot\xe8que",	"biblioth\xe8que",
	"bientot",	"bient\xf4t",
	"boeuf",	"b\x9cuf",
	"boeufs",	"b\x9cufs",
	"bonnification",	"bonification",
	"bonnifications",	"bonifications",
	"boussolle",	"boussole",
	"Br\xe9zil",	"Br\xe9sil",
	"buletin",	"bulletin",
	"carefour",	"carrefour",
	"ceal",	"cela",
	"celleci",	"celle-ci",
	"cellesci",	"celles-ci",
	"celuici",	"celui-ci",
	"celulle",	"cellule",
	"cel\xe0",	"cela",
	"cetrain",	"certain",
	"ceuxci",	"ceux-ci",
	"chaqun",	"chacun",
	"charette",	"charrette",
	"chateau",	"ch\xe2teau",
	"chifre",	"chiffre",
	"chifres",	"chiffres",
	"choeur",	"ch\x9cur",
	"choeurs",	"ch\x9curs",
	"circonstantiel",	"circonstanciel",
	"cleui",	"celui",
	"client\xe9le",	"client\xe8le",
	"cnet",	"cent",
	"coeur",	"c\x9cur",
	"coeurs",	"c\x9curs",
	"comerce",	"commerce",
	"cometre",	"commettre",
	"concesion",	"concession",
	"concesions",	"concessions",
	"concluse",	"conclue",
	"concurence",	"concurrence",
	"confidenciel",	"confidentiel",
	"contencieux",	"contentieux",
	"contre-ordre",	"contrordre",
	"controle",	"contr\xf4le",
	"corection",	"correction",
	"corections",	"corrections",
	"couleru",	"couleur",
	"courament",	"couramment",
	"creer",	"cr\xe9\x65r",
	"cr\xe9\x65\x65",	"cr\xe9\xe9\x65",
	"cr\xeame",	"cr\xe8me",
	"curiculum",	"curriculum",
	"c\xf4t\xe9l\xe0",	"c\xf4t\xe9-l\xe0",
	"d'ou",	"d'o\xf9",
	"deun",	"d'un",
	"deune",	"d'une",
	"dexu",	"deux",
	"dictionaire",	"dictionnaire",
	"dilemne",	"dilemme",
	"dilemnes",	"dilemmes",
	"diplome",	"dipl\xf4me",
	"disponnible",	"disponible",
	"disponnibles",	"disponibles",
	"dnas",	"dans",
	"dnot",	"dont",
	"domages",	"dommages",
	"dse",	"des",
	"d\xe9gr\xe9vement",	"d\xe9gr\xe8vement",
	"d\xe9ja",	"d\xe9j\xe0",
	"d\xe9marer",	"d\xe9marrer",
	"d\xe9panage",	"d\xe9pannage",
	"d\xe9paner",	"d\xe9panner",
	"d\xe9pot",	"d\xe9p\xf4t",
	"d\xe9veloper",	"d\xe9velopper",
	"ech\xe9\x61nce",	"\xe9\x63h\xe9\x61nce",
	"ech\xe9\x61nces",	"\xe9\x63h\xe9\x61nces",
	"efets",	"effets",
	"embarasser",	"embarrasser",
	"emmission",	"\xe9mission",
	"enr\xe9gistrer",	"enregistrer",
	"enveloper",	"envelopper",
	"erronn\xe9",	"erron\xe9",
	"erronn\xe9s",	"erron\xe9s",
	"espagne",	"Espagne",
	"Estce",	"Est-ce",
	"etait",	"\xe9tait",
	"EtatsUnis",	"Etats-Unis",
	"etats-Unis",	"Etats-Unis",
	"ete",	"\xe9t\xe9",
	"excelent",	"excellent",
	"excelents",	"excellents",
	"exelent",	"excellent",
	"exelents",	"excellents",
	"exigeance",	"exigence",
	"falange",	"phalange",
	"faloir",	"falloir",
	"ficheir",	"fichier",
	"ficheirs",	"fichiers",
	"filialle",	"filiale",
	"filliale",	"filiale",
	"financiaire",	"financi\xe8re",
	"fios",	"fois",
	"fl\xea\x63he",	"fl\xe8\x63he",
	"foetal",	"f\x9ctal",
	"foetale",	"f\x9ctale",
	"foetales",	"f\x9ctales",
	"foetaux",	"f\x9ctaux",
	"foetus",	"f\x9ctus",
	"fonctionaire",	"fonctionnaire",
	"fonctioner",	"fonctionner",
	"Francais",	"Fran\xe7\x61is",
	"france",	"France",
	"francofone",	"francophone",
	"fuire",	"fuir",
	"gasom\xe8tre",	"gazom\xe8tre",
	"gestionaire",	"gestionnaire",
	"globul",	"globule",
	"goufre",	"gouffre",
	"grande-bretagne",	"Grande-Bretagne",
	"griffoner",	"griffonner",
	"gr\xe0\x63\x65",	"gr\xe2\x63\x65",
	"g\xe8rer",	"g\xe9rer",
	"hipocrisie",	"hypocrisie",
	"hors-d'oeuvre",	"hors-d'\x9cuvre",
	"Htp",	"http",
	"Http",	"http",
	"http:\\\\",	"http://",
	"http:11",	"http://",
	"h\xe9moragie",	"h\xe9morragie",
	"icone",	"ic\xf4ne",
	"impressionisme",	"impressionnisme",
	"inclu",	"inclus",
	"inclue",	"incluse",
	"ind\xe9mniser",	"indemniser",
	"ind\xe9pendent",	"ind\xe9pendant",
	"innitialiser",	"initialiser",
	"innonder",	"inonder",
	"inovation",	"innovation",
	"intervale",	"intervalle",
	"int\xe9ret",	"int\xe9r\xeat",
	"int\xe9rresser",	"int\xe9resser",
	"irlande",	"Irlande",
	"italie",	"Italie",
	"jamias",	"jamais",
	"ipad"			  "iPad",
	"ipod"			  "iPod",
	"iphone",		  "iPhone",
	"jusqu'a",	"jusqu'\xe0",
	"jusquau",	"jusqu'au",
	"jutse",	"juste",
	"litterature",	"litt\xe9rature",
	"lse",	"les",
	"luxembourg",	"Luxembourg",
	"main-d'oeuvre",	"main-d'\x9cuvre",
	"maisonette",	"maisonnette",
	"mal\xe9\x61\x62le",	"mall\xe9\x61\x62le",
	"maniere",	"mani\xe8re",
	"manoeuvre",	"man\x9cuvre",
	"manoeuvrer",	"man\x9cuvrer",
	"manoeuvres",	"man\x9cuvres",
	"manoeuvrier",	"man\x9cuvrier",
	"manoeuvriers",	"man\x9cuvriers",
	"manoeuvri\xe8re",	"man\x9cuvri\xe8re",
	"manoeuvri\xe8res",	"man\x9cuvri\xe8res",
	"manoeuvr\xe9",	"man\x9cuvr\xe9",
	"manoeuvr\xe9\x65",	"man\x9cuvr\xe9\x65",
	"manoeuvr\xe9\x65s",	"man\x9cuvr\xe9\x65s",
	"manoeuvr\xe9s",	"man\x9cuvr\xe9s",
	"marronier",	"marronnier",
	"memoire",	"m\xe9moire",
	"mexique",	"Mexique",
	"milion",	"million",
	"millon",	"million",
	"mions",	"moins",
	"mod\xe9le",	"mod\xe8le",
	"moeurs",	"m\x9curs",
	"mourrir",	"mourir",
	"m\xe8me",	"m\xeame",
	"M\xe9\x64iterann\xe9\x65",	"M\xe9\x64iterran\xe9\x65",
	"m\xe9motechnique",	"mn\xe9motechnique",
	"noeud",	"n\x9cud",
	"noeuds",	"n\x9cuds",
	"nourir",	"nourrir",
	"nouriture",	"nourriture",
	"occupper",	"occuper",
	"occurence",	"occurrence",
	"occurences",	"occurrences",
	"ocuper",	"occuper",
	"ocurrence",	"occurrence",
	"ocurrences",	"occurrences",
	"oecum\xe9nique",	"\x9c\x63um\xe9nique",
	"oecum\xe9niques",	"\x9c\x63um\xe9niques",
	"oecum\xe9nisme",	"\x9c\x63um\xe9nisme",
	"Oedipe",	"\x8c\x64ipe",
	"oed\xe8me",	"\x9c\x64\xe8me",
	"oeil",	"\x9cil",
	"oeil-de-boeuf",	"\x9cil-de-b\x9cuf",
	"oeil-de-chat",	"\x9cil-de-chat",
	"oeillade",	"\x9cillade",
	"oeillades",	"\x9cillades",
	"oeillet",	"\x9cillet",
	"oeilleton",	"\x9cilleton",
	"oeilletons",	"\x9cilletons",
	"oeillets",	"\x9cillets",
	"oeill\xe8re",	"\x9cill\xe8re",
	"oeill\xe8res",	"\x9cill\xe8res",
	"oeils-de-boeuf",	"\x9cils-de-b\x9cuf",
	"oeils-de-chat",	"\x9cils-de-chat",
	"oenologie",	"\x9cnologie",
	"oenologique",	"\x9cnologique",
	"oenologiques",	"\x9cnologiques",
	"oenologue",	"\x9cnologue",
	"oenologues",	"\x9cnologues",
	"oesophage",	"\x9csophage",
	"oesophages",	"\x9csophages",
	"oestrog\xe8ne",	"\x9cstrog\xe8ne",
	"oeuf",	"\x9cuf",
	"oeufs",	"\x9cufs",
	"oeuvre",	"\x9cuvre",
	"oeuvrer",	"\x9cuvrer",
	"oeuvres",	"\x9cuvres",
	"oeuvr\xe9",	"\x9cuvr\xe9",
	"oeuvr\xe9\x65",	"\x9cuvr\xe9\x65",
	"oeuvr\xe9\x65s",	"\x9cuvr\xe9\x65s",
	"oeuvr\xe9s",	"\x9cuvr\xe9s",
	"oficiel",	"officiel",
	"oficiels",	"officiels",
	"ofre",	"offre",
	"ofres",	"offres",
	"Paques",	"P\xe2ques",
	"parafine",	"paraffine",
	"paral\xe8lle",	"parall\xe8le",
	"paral\xe8lles",	"parall\xe8les",
	"paranoyaque",	"parano\xef\x61que",
	"peid",	"pied",
	"pere",	"p\xe8re",
	"personalit\xe9",	"personnalit\xe9",
	"personel",	"personnel",
	"peut-t'il",	"peut-il",
	"peut-t'on",	"peut-on",
	"peut-tu",	"peux-tu",
	"peux-t'il",	"peut-il",
	"peux-t'on",	"peut-on",
	"peux-t-il",	"peut-il",
	"peux-t-on",	"peut-on",
	"plein-pied",	"plain-pied",
	"plutot",	"plut\xf4t",
	"portugal",	"Portugal",
	"pouvior",	"pouvoir",
	"pret",	"pr\xeat",
	"problemme",	"probl\xe8me",
	"problemmes",	"probl\xe8mes",
	"professionel",	"professionnel",
	"professionelle",	"professionnelle",
	"professionelles",	"professionnelles",
	"professionels",	"professionnels",
	"proffesseur",	"professeur",
	"proffessionel",	"professionnel",
	"proffessionelle",	"professionnelle",
	"proffessionelles",	"professionnelles",
	"proffessionels",	"professionnels",
	"proffessionnel",	"professionnel",
	"proffessionnelle",	"professionnelle",
	"proffessionnelles",	"professionnelles",
	"proffessionnels",	"professionnels",
	"programe",	"programme",
	"programer",	"programmer",
	"programes",	"programmes",
	"p\xe9lerin",	"p\xe8lerin",
	"p\xe9lerinage",	"p\xe8lerinage",
	"p\xe9rif\xe9rique",	"p\xe9riph\xe9rique",
	"quelqun",	"quelqu'un",
	"questionaire",	"questionnaire",
	"quio",	"quoi",
	"quitance",	"quittance",
	"quitances",	"quittances",
	"racourci",	"raccourci",
	"raffinner",	"raffiner",
	"raffoller",	"raffoler",
	"rancoeur",	"ranc\x9cur",
	"rapel",	"rappel",
	"rapelle",	"rappelle",
	"rapeller",	"rappeler",
	"rapels",	"rappels",
	"recepiss\xe9",	"r\xe9\x63\xe9piss\xe9",
	"recomand\xe9",	"recommand\xe9",
	"recomand\xe9\x65",	"recommand\xe9\x65",
	"ref\xe9rence",	"r\xe9\x66\xe9rence",
	"ref\xe9rences",	"r\xe9\x66\xe9rences",
	"rem\xe8\x64ier",	"rem\xe9\x64ier",
	"resembler",	"ressembler",
	"resentir",	"ressentir",
	"resortir",	"ressortir",
	"rhytme",	"rythme",
	"rhytmes",	"rythmes",
	"rintroduire",	"r\xe9introduire",
	"royaume-uni",	"Royaume-Uni",
	"r\xe8gler",	"r\xe9gler",
	"r\xe9\x66\x65rence",	"r\xe9\x66\xe9rence",
	"r\xe9\x66\x65rences",	"r\xe9\x66\xe9rences",
	"r\xe9\x66lection",	"r\xe9\x66lexion",
	"r\xe9\x66\xe8rence",	"r\xe9\x66\xe9rence",
	"r\xe9\x66\xe8rences",	"r\xe9\x66\xe9rences",
	"r\xe9glement",	"r\xe8glement",
	"r\xe9hausser",	"rehausser",
	"r\xe9ouvrir",	"rouvrir",
	"soci\xe8t\xe9",	"soci\xe9t\xe9",
	"soeur",	"s\x9cur",
	"soeurs",	"s\x9curs",
};

#define DEFWORDCNT_FRN  (sizeof(g_szDefWords_FRN)/sizeof(g_szDefWords_FRN[0]))
