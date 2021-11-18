#include <stdio.h> //"cabeçalho padrão de entrada/saída", this is a  preprocessor command
#include <stdlib.h> //possui funções envolvendo alocação de memória, controle de processos, conversões e outras 

// definindo constantes
#define ALTURA 20
#define LARGURA 15
#define NOVA_LINHA '\n'

int fun(int arg) { // declarando e implementando a função 'fun' que será usada dentro do main()
    return 2+arg;
}

int foo(int bar); // declarando a função foo. Esta função esta implementada no final.

void print_big(int number); /* void -> função que não tem return */

int soma (int num) {
       static int total = 0; // usando static a variável total se torna acessível dentro do main
       total += num;
       return total;
   }

void addone(int *n) { // n aqui é um pointer que aponta para um endereço de memória fora do escopo da função
    (*n)++;
}

typedef struct { // criando uma estrutura que será usada na função a seguir
  char * name; // a estrutura person possui 2 atributos name e age
  int age;
} person;

void birthday(person * p){ // criando uma função que acessa uma estrutura
    p->age++; // neste caso acessamos o atributo age da estrutura person e adicionamos 1
}

unsigned int fatorial(unsigned int x) // construindo função recursiva
/*Um int vai de -2147483648 à 2147483647. Um unsigned int vai de 0 à 4294967295.*/
{
    if (x == 0 || x == 1)
    {
        /* Terminating case */
        return 1;
    }
    else if (x > 1)
    {
        /* Recursive step */
        return x * fatorial(x-1);
    }
}

int main() { //main function where the program execution begins
    // imprimindo
    printf("\n Olá mundo!");

    // definindo variáveis inteiras e reais
    int a=0, d=3, e=4;
    int oc1=07, oc2=02, oc3; //octal values
    int hex1=0xf, hex2=0x2, hex3; //hexadecimal values
    char letra_1='x'; //char ten apenas 1 byte e é um tipo de int
    float b=1.3e-1; // b=1.3x10^(-1)=0.13
    double c=2.0;
    float sum;

    // fazendo operações com as variáveis acima
    a= d+c*d-c;
    sum= a+b+c;
    oc3=oc1+oc2;
    hex3=hex1-hex2;
    printf("\n a = %d",a); /*Vai imprimir o novo valor de a.*/
    printf("\n A soma de a, b e c é: %.2f.", sum,"\n");
    printf("\n oc3 = %o, hex3 = %x", oc3, hex3);
    printf("\n letra_1 = %c", letra_1);

    // utilizando constantes definidas no préprocessamento
    int area;

    area = ALTURA * LARGURA;

    printf("%c", NOVA_LINHA);
    printf("O valor da área é: %d", area);

    // definindo constantes e especidficando o tipo
    const float RAIO = 12.5;
    float arear;

    arear = 3.14 * RAIO * RAIO;

    printf("%c", NOVA_LINHA);
    printf("O valor da área é: %.2f", arear);

    /*imprimindo o endereço de uma variável*/

    printf("\n O endereço de arear é %p", &arear);

    /*usando ternário (codition ? true : false) em C*/

    arear ? printf("\n arear != 0") : printf("\n arear = 0");

    /*criando um loop infinito

    for( ; ; ) {
      printf("This loop will run forever.\n");
    }
    
    */

    /*definindo array*/
    int numeros[3];
    /*populando o array*/
    numeros[0]=3;
    numeros[1]=9;
    numeros[2]=12;
    numeros[3]=15;
    printf("\n O segundo \t elemento do array é %d.", numeros[1]); // \t dá um tab

    /*vamos declarar um array bidimensional*/
    int aa[2][2] = {{11,12},{21,22}};
    int val = aa[0][0];
    printf("\n aa[0][0]= %d",val);

    /*vamos declarar um multiarray de notas para duas disciplinas*/
    float M_F[2][3], media;
    int i, j;
    /*vamos popular o array*/
    M_F[0][0]=7.5;
    M_F[0][1]=8.2;
    M_F[0][2]=6.5;
    M_F[1][0]=7.4;
    M_F[1][1]=9.1;
    M_F[1][2]=7.9;

    /*vamos usar for para calcular a media das notas*/
    for (i=0; i<2; i++) {
        media=0;

        for (j=0; j<3; j++) {
            media += M_F[i][j]; /*media = media + M_F[i][j]*/
        }
        media /= 3.0;
        printf("\n A média em %d é: %.2f", i, media);
	}

    /*usando if e else*/
    if (a > b) {
        printf("\n %d é maior que %.2f.", a, b);
    } else {
        printf("\n %.2f é maior que %d.", b, a);
    }

    /*usando && para and e || para or*/
    c=10;
    if (a > b && a > c) {
        printf("\n %d é maior que %.2f e %.2f.", a, b, c);
    } else if (a < b && a < c) {
        printf("\n %d é menor que %.2f e %.2f.", a, b, c);
    } else if (a > b || a > c) {
        printf("\n %d é maior que %.2f ou %.2f.", a, b, c);
    }

    // usando diferente
    int alvo = 9;
    if (alvo != 10) {
    printf("\n Alvo não é igual a 10.");
    }

    /*strings são arrays de caracteres
    vamos definir uma string*/
    char nome[]= "Franciele";
    //ou 
    char name[5]= "Luis"; 
    // comprimento do array deve ser 1 a mais que o comprimento da string
    printf("\n %s tem %d anos de idade.", name, a);
    // imprimindo o comprimento da string
    printf("\n O número de caracteres de %s é %d.", nome, strlen(nome));
    // comparando strings
    if (strncmp(nome, "Fran", 4) == 0) {
        printf("\n Olá, Fran.");
    } else {
        printf("Você não é Fran.");
    }

    // concatenando strings
    char dest[18]="Hello";
    char src[7]=" World";
    strncat(dest,src,6);
    printf("\n %s",dest);
    strncat(dest,src,20);
    printf("\n %s",dest);

    // usando while + break + continue

    int n=0;
    while (1) 
    {
        n++; // soma n+1

        if (n % 2 ==1) // verificando se número é ímpar
        {
            continue; // segue o while
        }
    
    printf("\n O número %d é par.", n);

    if (n == 10)
    {
        break; // para o while
    }
    }

    int array[] = {1, 7, 4, 5, 9, 3, 5, 11, 6, 3, 34};
    n = 0;

    while (n < 10) {
        if(array[n] < 5){
            n++;
            continue;
        }

        if(array[n] > 10){
            break;
        }

        printf("\n %d", array[n]);
        n++;
    }

    printf("\n O valor de fun é %d.", fun(1));

    printf("\n O valor de foo é %d.", foo(1));

    for (i = 0; i < 11; i++) {
    print_big(array[i]);
    }

    printf("\n %d", soma(3)); 
    printf("\n %d", soma(23)); 
    printf("\n %d", soma(33));  

    /*definindo strings usando um pointer*/

    char * nomee= "Ana";

    printf("\n O número de caracteres de %s é %d.", nomee, strlen(nomee));

    n = 10;
    
    int * pointer_to_n = &n; // usando pointer para desreferenciar a variável n
    
    *pointer_to_n += 1; // adicionando 1 a variável n, usando pointer
     
    printf("\n Done! n=%d", n);

    /* vamos usar struct para criar um "ponto" com três coordenadas
    cada uma de um tipo diferente */


    struct ponto
    {
        int p1;
        float p2;
        char * p3;
    };
    
    struct ponto p;
    p.p1=1;
    p.p2=1.3;
    p.p3="três";

    printf("\n %d, %f, %s", p.p1, p.p2, p.p3);

    // usando typedef para facilitar a criação de structs

    typedef struct {
        char * marca;
        int ano;
    } veiculo;

    veiculo meu_carro;
    veiculo Luis_carro;

    meu_carro.marca= "Chevrolet";
    meu_carro.ano= 2013;

    Luis_carro.marca= "Gurgel";
    Luis_carro.ano= 1960;

    printf("\n Tenho um carro da marca %s, ano %d.", meu_carro.marca, meu_carro.ano);
    printf("\n Luis tem um carro da marca %s, ano %d.", Luis_carro.marca, Luis_carro.ano);

    
    printf("\n Before: %d", n);
    addone(&n); // devemos passar uma referência à variável n, e não à própria variável
    printf("\n After: %d", n);

    person joao;
    joao.name = "João";
    joao.age = 27;
    printf("\n %s tem %d anos de id ade.", joao.name, joao.age);
    birthday(&joao);
    printf("\n Feliz aniversário! %s tem agora %d anos.", joao.name, joao.age);

    /*vamos alocar dinamicamente apenas o suficiente para manter uma struct person na memória e,
    em seguida, retornar um ponteiro do tipo person para os dados recém-alocados.*/ 

    person * nova_pessoa = (person *) malloc(sizeof(person));

    // vamos acessar os membros de person

    nova_pessoa->name= "Pedro";
    nova_pessoa->age= 26;

    printf("\n %s tem %d anos de idade.", nova_pessoa->name, nova_pessoa->age);

    // vamos desalocar a memória de nova_pessoa

    free(nova_pessoa);

    // vamos verificar que a memória foi liberada

    printf("\n %s tem %d anos de idade.", nova_pessoa->name, nova_pessoa->age);

    // vamos usar pointers para arrays 

    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    char * pvowels = vowels;
    
    // Print the addresses
    for (i = 0; i < 5; i++) {
    printf("\n &vowels[%d]: %p, pvowels + %d: %p, vowels + %d: %p", i, &vowels[i], i, pvowels + i, i, vowels + i);
    }
    // Print the values
    for (i = 0; i < 5; i++) {
    printf("\n vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c", i, vowels[i], i, *(pvowels + i), i, *(vowels + i));
    }

    // vamos alocar dinamicamente um array de comprimento 3
    n=3;
    char * pvogais = (char *) malloc(n * sizeof(char)); 

    pvogais[0]='k';
    pvogais[1]='y';
    pvogais[2]='w';

    for (i = 0; i < n; i++) {
    printf("\n %c ", pvogais[i]);
    }

    free(pvogais);

    // vamos alocar dinamicamente um array de 2 linhas e 3 colunas 
    // primeiro passo: vamos definir um pointer 2D
    float** pnumbers;
    // agora vamos alocar espaço para duas linhas
    int nl=2, nc=3;
    pnumbers = (float**) malloc(nl* sizeof(float*));
    /* se o array for de caracteres, pulamos o cabeca passo e fazemos:
    char ** pvogais = (char **) malloc(nl * sizeof(char *)); */
    // segundo passo: vamos alocar espaço para os elementos das colunas dentro de cada linha
    pnumbers[0] = (float*) malloc(nc* sizeof(float));
    pnumbers[1] = (float*) malloc(nc* sizeof(float));
    // terceiro passo: vamos popular o array

    for (i = 0; i < nl; i++)
    {
        for (j = 0; j < nc; j++)
        {
            pnumbers[i][j]= i*0.1+j*0.01;
            printf("\n %.2f", pnumbers[i][j]);
        }
        
    }

    // vamos liberar a memória de pnumbers
    for (i = 0; i < nl; i++)
    {
        free(pnumbers[i]);
    }
    free(pnumbers);
    
    // imprimindo resultado de função recursiva
    printf("\n O fatorial de 12 é %d", fatorial(12));

    return 0;
}

int foo(int bar) {  // implementando a função foo
    return bar + 1;
}

void print_big(int number){ //implementando a função print_big
    if(number > 10){
        printf("\n %d is big.",number);
    }
}