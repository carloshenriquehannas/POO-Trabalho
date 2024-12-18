/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 2)
*/

/*
    Utilizei o seguinte link para sobescrever os metodos de print quando ha classes derivadad:
    https://terminalroot.com.br/2021/06/o-que-significa-override-em-cpp.html
*/

#include <iostream>

// Classe dos numeros complexos C
class C                         
{
    private:
        double _real, _imag;

    public:
        C(double real = 0, double imag = 0): _real(real), _imag(imag) {}    // Construtor de complexos. Default '0' para parte real e imaginaria
        
        double getReal() const                                              // Metodo auxiliar que retorna o atributo real da classe
        {
            return _real;
        }

        virtual void print(std::ostream& out) const                         // Imprime numero complexo no formato requerido
        {
            out << _real << " + " << _imag << "i";
        }

        friend std::ostream& operator<<(std::ostream& out, const C& c)      // Metodo auxiliar para impressao  
        {
            c.print(out);

            return out;
        }
};

// Classe dos numeros reais R (R herda de C)
class R : public C
{
    public:
        R(double real = 0): C(real) {}                                      // Construtor dos numero reais. Default '0' para numero real
        
        void print(std::ostream& out) const override                        // Imprime numero real no formato requerido
        {
            out << getReal();
        }
};

// Classe dos numeros racionais Q (Q herda de R)
class Q : public R
{
    private:
        int _numerador, _denominador;

    public:
        Q(int numerador = 0, int denominador = 1): R(static_cast<double>(numerador) / denominador), _numerador(numerador), _denominador(denominador) {}  // Construtor dos numero racionais. Default '0' para numerador e '1' para denominador

        int getNumerador() const                                            // Metodo auxiliar que retorna o numerador
        {
            return _numerador;
        }

        int getDenominador() const                                           // Metodo auxiliar que retorna o denominador
        {
            return _denominador;
        }

        void print(std::ostream& out) const override                        // Imprime numero racional no formato requerido
        {
            out << getNumerador() << "/" << getDenominador();
        }
};

// Classe dos numeros inteiros Z (Z herda de Q)
class Z : public Q
{
    public:
        Z(int inteiro = 0): Q(inteiro) {}                                   // Construtor dos numero inteiros. Default '0' para numero inteiro                                                               
        
        void print(std::ostream& out) const override                        // Imprime numero inteiro no formato requerido
        {
            if (getNumerador() > 0)
                out << "+";
            out << getNumerador();
        }
};

// Classe dos numeros naturais N (N herda de Z)
class N : public Z
{
    public:
        N(int natural = 0): Z(natural) {}                                   // Construtor dos numeros naturais. Default '0' para numero natural
        
        void print(std::ostream& out) const override                        // Imprime numero natural no formato requerido
        {
            out << getNumerador();
        }
};

int main() {
    const int n = 201; 
    C* objetos[n];
    
    // Comandos de entrada que instancia objeto de cada classe
    objetos[0] = new Z(-502739797);
    objetos[1] = new R(8394.76384138559);
    objetos[2] = new Z(1356484275);
    objetos[3] = new Q(724201869, 1853242002);
    objetos[4] = new Z(-1845119981);
    objetos[5] = new R(-5286.785248717225);
    objetos[6] = new N(1963476986);
    objetos[7] = new R(-5078.877951374705);
    objetos[8] = new C(4157.587983668502, -2870.034424367105);
    objetos[9] = new Z(1138579157);
    objetos[10] = new Q(1464289803, 1678157713);
    objetos[11] = new C(-5645.470842566169, 2412.3260097590337);
    objetos[12] = new N(1567994110);
    objetos[13] = new R(4765.76994147281);
    objetos[14] = new C(4767.41124766491, -4887.2760516472335);
    objetos[15] = new Z(773436792);
    objetos[16] = new Q(671449760, 1943016602);
    objetos[17] = new C(6232.463049750648, 7826.327521271742);
    objetos[18] = new N(285700865);
    objetos[19] = new Q(-493139948, 1623013138);
    objetos[20] = new R(-9962.453891501436);
    objetos[21] = new C(-3451.6131464443743, -983.1654999811399);
    objetos[22] = new R(-61.54021854035091);
    objetos[23] = new C(-2004.2505908318726, 6438.358409770415);
    objetos[24] = new N(1615835296);
    objetos[25] = new R(6364.34035775709);
    objetos[26] = new Q(-1769787148, 481303850);
    objetos[27] = new R(-3030.407747077068);
    objetos[28] = new N(1966560862);
    objetos[29] = new Z(1975382838);
    objetos[30] = new N(854900786);
    objetos[31] = new C(7534.456366752522, -333.13588074271684);
    objetos[32] = new R(1753.3132063922294);
    objetos[33] = new C(8738.46618601579, 4255.365185139572);
    objetos[34] = new Z(143943644);
    objetos[35] = new C(3689.3956894300572, -3702.3607299044816);
    objetos[36] = new Q(-843728490, 1815582154);
    objetos[37] = new Z(730222076);
    objetos[38] = new R(-5444.134502300771);
    objetos[39] = new C(-5014.510345902982, -1808.0420900341014);
    objetos[40] = new Q(-33948980, 988548253);
    objetos[41] = new R(4501.488785755057);
    objetos[42] = new Z(364167815);
    objetos[43] = new C(8056.964018321443, 1216.0450458019914);
    objetos[44] = new N(411364582);
    objetos[45] = new C(5433.072213248161, 6738.951825285501);
    objetos[46] = new Z(-1117951245);
    objetos[47] = new C(-5668.33783048357, 8653.799034037507);
    objetos[48] = new Z(-263120149);
    objetos[49] = new R(-5667.214497737363);
    objetos[50] = new N(423862767);
    objetos[51] = new R(-6085.795105519854);
    objetos[52] = new Z(726134362);
    objetos[53] = new R(-6235.380092086038);
    objetos[54] = new C(-7323.790196237623, -753.2949404442006);
    objetos[55] = new Z(1261116089);
    objetos[56] = new Q(-670340391, 466219497);
    objetos[57] = new Z(2088459185);
    objetos[58] = new R(797.3722985405329);
    objetos[59] = new N(1494057463);
    objetos[60] = new C(-7756.740032073152, -8605.564382923092);
    objetos[61] = new R(6819.092221253166);
    objetos[62] = new Z(-46172270);
    objetos[63] = new R(-9140.354905545571);
    objetos[64] = new N(1876859016);
    objetos[65] = new Z(1680881010);
    objetos[66] = new Q(-1929163295, 1328691679);
    objetos[67] = new N(1360130039);
    objetos[68] = new Z(-841931209);
    objetos[69] = new C(1144.722469387114, 9593.321722411089);
    objetos[70] = new Q(-693026443, 909363963);
    objetos[71] = new N(1699464394);
    objetos[72] = new Z(1802878655);
    objetos[73] = new R(1522.1653493860267);
    objetos[74] = new N(1915266959);
    objetos[75] = new Z(1194388514);
    objetos[76] = new Q(-464514644, 427163290);
    objetos[77] = new N(1245401296);
    objetos[78] = new Q(-372747145, 1155068321);
    objetos[79] = new Z(-1762644031);
    objetos[80] = new R(-3418.866129956995);
    objetos[81] = new Z(1697064266);
    objetos[82] = new C(-2955.499922585059, 6755.116272119394);
    objetos[83] = new Z(-536511010);
    objetos[84] = new Q(-1833229363, 1405049667);
    objetos[85] = new C(7918.963188480662, 7745.817924661085);
    objetos[86] = new R(-1082.5523870387315);
    objetos[87] = new Q(1851023322, 947510783);
    objetos[88] = new Z(-1116684945);
    objetos[89] = new C(5581.499501545706, -9164.764960116667);
    objetos[90] = new N(825451216);
    objetos[91] = new R(-3346.2146790065362);
    objetos[92] = new Z(1963001856);
    objetos[93] = new C(-4791.3018245283465, 8389.438046491065);
    objetos[94] = new Z(649229164);
    objetos[95] = new C(5693.2746768162815, 4801.42429974263);
    objetos[96] = new Z(-1175540000);
    objetos[97] = new R(9099.077935118992);
    objetos[98] = new N(1945651611);
    objetos[99] = new C(-4450.145730222812, -3850.87821178135);
    objetos[100] = new Z(-998865609);
    objetos[101] = new Q(-697483360, 282685699);
    objetos[102] = new R(-1075.900590983727);
    objetos[103] = new Z(-1387454030);
    objetos[104] = new Q(-1970663056, 1838292834);
    objetos[105] = new Z(-937327595);
    objetos[106] = new R(2732.165414781195);
    objetos[107] = new Z(1885539256);
    objetos[108] = new C(-4001.83954292773, -4159.438179033051);
    objetos[109] = new Z(-210330241);
    objetos[110] = new R(-4322.3386892734725);
    objetos[111] = new Z(1389496185);
    objetos[112] = new Q(724622272, 471517833);
    objetos[113] = new C(9627.793107956742, 5026.777919849017);
    objetos[114] = new N(1597391344);
    objetos[115] = new C(7853.492099424355, -2185.490936414396);
    objetos[116] = new R(-6434.146622074823);
    objetos[117] = new Z(-1323566298);
    objetos[118] = new R(-1519.2477583420587);
    objetos[119] = new Q(-1756284564, 686043909);
    objetos[120] = new C(375.38437142698785, -9006.313533970753);
    objetos[121] = new N(39354687);
    objetos[122] = new Z(1710836232);
    objetos[123] = new R(-1539.8114283260056);
    objetos[124] = new C(8944.720822260704, 1348.975553761642);
    objetos[125] = new Q(926977357, 1372982259);
    objetos[126] = new C(9698.352538080551, -1035.7549015186996);
    objetos[127] = new Q(327765980, 608030836);
    objetos[128] = new C(8463.510075990198, -5751.75041722003);
    objetos[129] = new Q(-1061918789, 2144119970);
    objetos[130] = new C(-2412.4889031109096, -755.3135534345693);
    objetos[131] = new Z(-2123771344);
    objetos[132] = new C(9188.52165484528, -3351.3741841302535);
    objetos[133] = new N(115416742);
    objetos[134] = new R(-9691.453135717236);
    objetos[135] = new N(1606470950);
    objetos[136] = new Q(-201869975, 376169404);
    objetos[137] = new C(-8201.963783086321, -5473.544715511347);
    objetos[138] = new N(827907376);
    objetos[139] = new Q(-1004345237, 471829337);
    objetos[140] = new N(1844931457);
    objetos[141] = new Z(-1180706091);
    objetos[142] = new Q(-845282707, 1095542561);
    objetos[143] = new N(55805853);
    objetos[144] = new R(-3692.6937552503423);
    objetos[145] = new Q(-208181744, 1789509959);
    objetos[146] = new Z(645390138);
    objetos[147] = new C(5301.571469339808, -487.797470256879);
    objetos[148] = new N(1812314634);
    objetos[149] = new Z(-1836008789);
    objetos[150] = new N(1007241960);
    objetos[151] = new C(1707.6336103504163, -9045.38670148051);
    objetos[152] = new N(631275088);
    objetos[153] = new C(-4845.398157814961, -5619.6564391077745);
    objetos[154] = new N(1157073504);
    objetos[155] = new Q(173594685, 860849643);
    objetos[156] = new Z(-1880595480);
    objetos[157] = new Q(1628739494, 222749999);
    objetos[158] = new Z(-521577900);
    objetos[159] = new R(-6152.657521333105);
    objetos[160] = new C(-7928.527603165407, 856.0878025713482);
    objetos[161] = new R(5129.433121966833);
    objetos[162] = new Z(-1471840267);
    objetos[163] = new N(112326095);
    objetos[164] = new Z(1850098297);
    objetos[165] = new C(610.2902206740109, 1395.728358440383);
    objetos[166] = new R(-9785.515717252738);
    objetos[167] = new C(1769.8924548712384, 5807.574341019095);
    objetos[168] = new N(1992072456);
    objetos[169] = new R(3843.176833395004);
    objetos[170] = new N(75688695);
    objetos[171] = new C(-8428.846127225152, -1756.7993472973758);
    objetos[172] = new R(-1526.3545369986568);
    objetos[173] = new Z(-959369384);
    objetos[174] = new C(-3404.2881379241117, -8918.77578710499);
    objetos[175] = new N(582489781);
    objetos[176] = new C(9106.237367917598, 138.95912580041477);
    objetos[177] = new N(808681933);
    objetos[178] = new R(-8819.072696332667);
    objetos[179] = new Q(1247534650, 1904075126);
    objetos[180] = new R(8653.13645566857);
    objetos[181] = new Z(-1418135682);
    objetos[182] = new Q(2133834494, 994711370);
    objetos[183] = new Z(1368238385);
    objetos[184] = new R(7301.999010814408);
    objetos[185] = new Q(-447017491, 1948096507);
    objetos[186] = new N(1562441057);
    objetos[187] = new Z(1609236550);
    objetos[188] = new Q(-280731203, 39946870);
    objetos[189] = new R(3346.89009327048);
    objetos[190] = new Q(764878322, 1669174825);
    objetos[191] = new R(4296.781610927877);
    objetos[192] = new Q(838604325, 1968202387);
    objetos[193] = new Z(2099356622);
    objetos[194] = new N(1463412156);
    objetos[195] = new Q(-2038815112, 569800828);
    objetos[196] = new N(1201023078);
    objetos[197] = new R(5477.440249732106);
    objetos[198] = new N(1074294044);
    objetos[199] = new Q(1305314301, 1547971688);
    objetos[200] = new C(2437.1746383151276, -4240.0025929678195);
    for (int i = 0; i < n; ++i)
        std::cout << *objetos[i] << std::endl;
    
    for (int i = 0; i < n; ++i)
        delete objetos[i];
    return 0;
}
