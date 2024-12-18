/*
    Aluno: Carlos Henrique Hannas de Carvalho. NUSP: 11965988
    SCC0604 - POO (Lista 2)
*/

#include <iostream>
#include <string>
#include <iomanip>

class BigInt
{
    private:
        int* _partes;
        int _npartes;
        bool _positivo;

    public:
        BigInt(std::string numero)                                  // Construtor de BigInt
        {
            int start = 0;                                          // Variavel auxiliar para verificar onde de fato comeca a string com numero

            _partes = new int[numero.length()];

            if(numero[0] == '-')                                    // Se a string possui sinal negativo
            {
                _positivo = false;
                start = 1;
            }
            else
            {
                _positivo = true;
            }

            while (start < numero.length() && numero[start] == '0') // Quantidade de zeros a esquerda
                start++;

            if (start == numero.length())                           // Se a string contem apenas zeros, armazena '0'
            {
                _npartes = 1;
                _partes = new int[_npartes]{0};
                _positivo = true;  
            } 
            else 
            {
                _npartes = numero.length() - start;                 // Tamanho do vetor: tamanho da string - zeros na esquerda
                _partes = new int[_npartes];

                // Converte cada caractere para dígito inteiro
                for (int i = _npartes - 1, j = 0; i >= 0; i--, j++)
                    _partes[i] = numero[start + j] - '0';
            }
        }

        BigInt(int num, bool eh_num = true)                         // Construtor de BigInt (atributos conforme enunciado)
        {
            if(eh_num)                                       // Situacao especificada em enunciado quando eh_num = true
            {
                if(num >= 0)                                 // Define qual deve ser o sinal do numero
                    _positivo = true;
                else    
                    _positivo = false;

                _npartes = 1;
                _partes = new int[_npartes];                 // Aloca memoria de _partes

                _partes[_npartes - 1] = num > 0 ? num : -num;

            }
            else                                             // Situacao especificada em enunciado quando eh_num = false
            {
                _positivo = true;
                _npartes = num;
                _partes = new int[_npartes];                 // Aloca memoria de _partes

                for(int i = _npartes - 1; i > 0; i--)
                    _partes[i] = 0;
            }
        }

        BigInt()                                                    // Construtor de BigInt (atributos conforme enunciado)
        {
            _positivo = true;
            _npartes = 1;

            _partes = new int[_npartes];                     // Aloca memoria de _partes
            _partes[_npartes - 1] = 0;
            
        }

        /*BigInt(BigInt&& b)
        {}*/

        ~BigInt()                                                   // Destruidor do BigInt
        {
            delete[] _partes;                                // Libera o vetor de _partes
        }

        bool positivo()                                             // Metodo para retornar true se for positivo; false caso contrario
        {
           return _positivo;
        }

        BigInt& operator=(const BigInt& b)                          // Metodo para realizar atribuicao de valor
        {
            if(this != &b)                                      // Se objeto atual for diferente do BigInt b
            {
                delete[] _partes;                         // Libera o vetor atual

                _positivo = b._positivo;                  // Atribui o sinal do BigInt b ao objeto atual
                _npartes = b._npartes;                    // Atribui o tamanho do BigInt b ao objeto atual

                _partes = new int[_npartes];              // Aloca o vetor atual com os parametros do BigInt b
                
                for(int i = 0; i < b._npartes; i++)
                    _partes[i] = b._partes[i];            // Atribui os elementos do BigInt b ao objeto atual
            }

            return *this;
        }

        BigInt abs()                                                // Metodo para retornar valor absoluto do numero
        {
            BigInt resultado = *this;                          // Cria copia do objeto atual

            resultado._positivo = true;                       // Torna _positivo como true, independente do valor atual
            
            return resultado;                                 // Retorna o modulo

        }

        friend bool operator==(const BigInt& a, const BigInt& b)    // Metodo para verificar se dois BigInt sao iguais
        {

            if(a._positivo != b._positivo || a._npartes != b._npartes)     // Verifica se possuem o mesmo sinal ou tamanho. Se nao, retorna false
                return false;                

            for(int i = 0; i < a._npartes; i++)               // Se possuem mesmo sinal e tamanho, verificar cada um dos elementos                     
            {
                if(a._partes[i] != b._partes[i])              // Verifica se possuem os mesmos elementos. Se nao, retorna false
                    return false;
            }

            return true;                                     // Retorna true se sao iguais
        }

        friend bool operator>(const BigInt& a, const BigInt& b)     // Metodo para comparar o tamanho de dois BigInt
        {
                if(a._positivo && !b._positivo)             // BigInt a positivo; BigInt b negativo
                    return true;

                if(!a._positivo && b._positivo)             // BigInt a negativo; BigInt b positivo
                    return false;

                // Casos que em possuem o mesmo sinal
                if(a._positivo)                             // Situacao que considera BigInt a positivo
                    if(a._npartes > b._npartes)             // Se tamanho de a for maior, retornar true
                        return true;
                    else                                    // Se nao, retornar false
                        return false;
                else                                        // Situacao que considera a negativo
                    if(a._npartes < b._npartes)             // Se tamananho de a for menor, retornar true
                        return true;
                    else                                    // Se nao, retornar false
                        return false;
                
                // Situacao de sinal e tamanho igual. Verifica elementos um a um 
                for(int i = 0; i < a._npartes; i++)
                    if(a._partes[i] < b._partes[i])
                        return false;
                
                return true;                            // Nessa situacao, elementos de a > elementos de b
        }

        /*friend BigInt operator+(const BigInt& a, const BigInt& b) 
        {
        }*/

        /*friend BigInt operator-(const BigInt& a, const BigInt& b)   
        {}*/

        BigInt operator-()                                          // Metodo para inverter o sinal do BigInt
        {
            BigInt resultado = *this;                          // Cria copia do objeto atual
            
            resultado._positivo = !resultado._positivo;        // Inverte o sinal

            return resultado;                                  // Retorna o sinal oposto
        }

        /*friend BigInt operator*(const BigInt& a, const BigInt& b)
        {}*/

        /*BigInt operator/(int b)
        {}*/

        /*friend BigInt operator^(const BigInt& a, const BigInt& b) 
        {}*/
        
        friend std::ostream& operator<<(std::ostream &out, const BigInt &a)
        {
            if (!a._positivo)                                             // Se numero for negativo, imprimir "-"
                out << "-"; 

            for(int i = a._npartes - 1; i >= 0; i--)
                out << a._partes[i];
    
            return out; 
        }
        
};

int main()
{
    BigInt numero = BigInt("01023");

    std::cout << numero << std::endl;

}