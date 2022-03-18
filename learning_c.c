#include <stdio.h> //"cabeçalho padrão de entrada/saída", this is a preprocessor command
#include <stdlib.h> //possui funções envolvendo alocação de memória, controle de processos, conversões e outras 
#include <errno.h> // ornece macros para identificar e relatar erros de execução através de códigos de erro
#include <string.h> // contém uma série de funções para manipular strings
#include "my_header.h" //meu header com as funções ao_cubo e MAX
#include <stdarg.h> // usado para trabalhar com funções com número variável de parâmentros

// definindo constantes de préprocessamento
#define ALTURA 20
#define LARGURA 15
#define NOVA_LINHA '\n'

// Vamos usar o operador de continução (\) e o operador (#) que transforma o parâmetro em string
#define  mensagem_para(a, b)  \
   printf("\n" #a " and " #b ": We love you!")

// o operador (##) serve para combinar dois argumentos
#define cola_token(n) printf ("\n token" #n " = %d", token##n)

extern int errno;

// declarando uma variável global
int global;
int a=111; // essa variável também está declarada dentro do main

/* Forma geral de uma função em C:

return_type function_name( parameter list ) {
   body of the function
} 
*/

int fun(int a) { // declarando e implementando a função 'fun' que será usada dentro do main()
    return a+1; // o valor de 'a' utilizado será o que está dentro do main
}

int foo(int); /* declarando a função foo. Esta função está implementada no final. Não é necessario colocar um nome para a 
variável apenas o seu tipo. Quando a implementação da função está em um arquivo diferente é necessário declarar a função 
no arquivo que chama a função*/

void print_big(int number); /* return_type = void -> função que não tem return */

int soma (int num) {
       static int total = 0; // usando static a variável total se torna acessível dentro do main
       total += num;
       return total;
   }

void addone(int *n) { // n aqui é um pointer que aponta para um endereço de memória fora do escopo da função
    (*n)++;
}

/* definindo uma estrutura simples */
struct {
    unsigned int validaLargura;
    unsigned int validaAltura;
} status1;

/* definindo uma estrutura com bit fields (variável com tamanho pré-definido) */
struct {
    unsigned int validaLargura : 1;
    unsigned int validaAltura : 1;
} status2;

// com a keyword typedef podemos dar um novo nome a um tipo
typedef unsigned char BYTE;

typedef struct { // criando uma estrutura que será usada na função a seguir
  char * name; // a estrutura person possui 2 atributos: name e age
  int age;
} person;

void birthday(person * p){ // criando uma função que acessa uma estrutura
    p->age++; // neste caso acessamos o atributo age da estrutura person e adicionamos 1
}

/* Uma union é um tipo de dado especial disponível em C que permite armazenar diferentes tipos de dados no mesmo local de memória
No entanto, apenas um membro pode conter um valor em um determinado momento */
union Data {
   int i;
   float f;
   char str[20];
};

double fatorial(unsigned int x) // construindo função recursiva
{
    if (x <= 1){
        /* Terminating case */
        return 1;
    }
    return x * fatorial(x - 1);
}

int fibonacci (int i) { // Outro exemplo de função recursiva
    if (i == 0)
    {
        return 0;
    }

    if (i == 1)
    {
        return 1;
    }
    return fibonacci(i-1) + fibonacci(i-2);
    
}

// vamos criar uma função com um número variável de parâmetros
double average(int num, ...) {
    va_list valist;
    double sum = 0.0;
    int i;

    /*Vamos inicializar valist para num argumentos*/
    va_start(valist, num);

     /*Agora vamos acessar os argumentos atribuidos a valist */
   for (i = 0; i < num; i++) {
      sum += va_arg(valist, int);
   }
	
   /*Limpando a mémoria reservada para valist */
   va_end(valist);

   return sum/num;
}

int main() { //main function where the program execution begins
    // imprimindo
    printf("\n Olá mundo!");

    // definindo variáveis locais a função main
    int a=1, d=3, e=4;
    int oc1=07, oc2=02, oc3; //octal values
    int hex1=0xf, hex2=0x2, hex3; //hexadecimal values
    char letra_1='x'; //char ten apenas 1 byte e é um tipo de int
    float b=1.3e-1; // b=1.3x10^(-1)=0.13
    double c=2.0;
    float divs;
    BYTE byte1=200; // por causa do typedef agora BYTE pode ser usado como abrevição de unsigned char

    // imoprimindo a variável 'a', a impressão será a da variável local
    printf("\n a = %d", a);

    // fazendo operações com as variáveis acima e com variável global
    global= a+d*e-d;
    divs= c/b;
    oc3=oc1+oc2;
    hex3=hex1-hex2;
    printf("\n global = %d",global); /*Vai imprimir o novo valor de 'a'*/
    printf("\n c/b = %.2f.", divs,"\n");
    printf("\n oc3 = %o, hex3 = %x", oc3, hex3);
    printf("\n letra_1 = %c", letra_1);
    printf("\n byte1 = %u", byte1);

    // utilizando constantes definidas no pré-processamento
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

    /*testando alguns macros pré-definidos*/
    printf("\n File :%s", __FILE__ );
    printf("\n Date :%s", __DATE__ );
    printf("\n Time :%s", __TIME__ );
    printf("\n Line :%d", __LINE__ );
    printf("\n ANSI :%d", __STDC__ );

    mensagem_para(John, Mary);

    int token3 = 23;
    cola_token(3);

    printf("\n 11 ao cubo é %d.", ao_cubo(11));

    printf("\n O máximo entre 2.3 e 3.2 é %.1f", MAX(2.3,3.2));

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

    // outra forma de criar e popular um array
    char vogais[] = {'a', 'e', 'i', 'o', 'u'};
    printf("\n Temos %d vogais.", sizeof(vogais));

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

    /*strings são arrays unidimensionais de caracteres terminados por um caractere nulo '\0'.
    vamos definir uma string*/
    char nome[]=  {'H', 'e', 'l', 'l', 'o', '\0'};
    //ou 
    char name[]= "Hello"; 

    printf("\n %s tem %d anos de idade.", nome, a);
    // imprimindo o comprimento da string
    printf("\n O número de caracteres de %s é %d.", name, strlen(name));
    // comparando strings
    if (strncmp(nome, "Fran", 4) == 0) {
        printf("\n Olá, Fran.");
    } else {
        printf("Você não é Fran.");
    }

    // concatenando strings
    char dest[18]="Hello";
    char src[7]=" World";
    strncat(dest,src,6); // C built-in function 
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

    printf("\n O valor de foo é %d.", foo(1));

    printf("\n O valor de fun é %d.", fun(1));

    printf("\n O valor de fun é %d.", fun(1));

    printf("\n O valor de foo é %d.", foo(1));

    for (i = 0; i < 11; i++) {
    print_big(array[i]);
    }

    printf("\n %d", soma(3)); 
    printf("\n %d", soma(23)); 
    printf("\n %d", soma(33));  

    // definindo um pointer
    int *intPointer; // um pointer é variável cujo valor é o endereço de outra variável
    /*O tipo de dados real do valor de todos os ponteiros é um número hexadecimal longo que representa um endereço de memória. 
    A única diferença entre ponteiros de diferentes tipos de dados é o tipo de dados da variável ou constante para a qual o 
    ponteiro aponta.*/

    // atribuindo o endereço de uma variável a um ponteiro
    intPointer = &d;
    printf("\n O endereço de d é %x", &d);
    printf("\n O valor de intPointer é %x", intPointer);
    printf("\n O valor de d é %d", d);
    printf("\n O valor disponível no endereço intPointer é %d", *intPointer);

    /*definindo strings usando um pointer*/

    char *nomee; //criando um pointer para um caracter sem especificar o seu tamanho

    nomee = malloc( 40 * sizeof(char) ); //Alocando memória dinamicamente 40 elementos do tipo char

    strcpy(nomee, "Anna Machado Pereira"); 

    printf("\n O número de caracteres de %s é %d.", nomee, strlen(nomee));

    free(nomee); // Liberando a memória novamente

    nomee = calloc(30, sizeof(char)); //Outro método de alocação

    strcpy(nomee, "Albert Einstein");

    printf("\n O número de caracteres de %s é %d.", nomee, strlen(nomee));

    free(nomee);

    n = 10;
    
    int *pointer_to_n = &n; // usando pointer para desreferenciar a variável n
    
    *pointer_to_n += 1; // adicionando 1 a variável n, usando pointer
     
    printf("\n Done! n=%d", n);

    /*struct é um tipo de dados definido pelo usuário disponível em C que permite combinar itens de dados de diferentes tipos,
    ao contrário de arrays que só podem ter dados do mesmo tipo */

    struct ponto
    {
        int p1;
        float p2;
        char p3[10];
    };
    
    struct ponto p;
    p.p1=1;
    p.p2=1.3;
    strcpy(p.p3, "três");

    printf("\n %d, %.2f, %s", p.p1, p.p2, p.p3);

    //vamos definir um pointer para uma struct

    struct ponto *pointer_to_p;

    // vamos armazenar o endereço de uma variável struct neste pointer

    pointer_to_p = &p;

    // vamos acessar os valores da variável

    printf("\n O valor p2 do ponto p é %.2f", pointer_to_p->p2);

    // vamos ver quanto espaço de memória ocupado pelas estrutura status1 e status2

    printf("\n O espaço de memória ocupado por status1 é: %d", sizeof(status1));
    printf("\n O espaço de memória ocupado por status2 é: %d", sizeof(status2));

    status2.validaAltura = 1;
    printf("\n status2.validaAltura = %d", status2.validaAltura);
    status2.validaAltura = 2;
    // O número 2 ocupa mais que 1 bit, por isso o valor de validaAltura será 0
    printf("\n status2.validaAltura = %d", status2.validaAltura);

    // usando typedef para facilitar a criação de structs

    typedef struct {
        char *marca; 
        int ano;
    } veiculo;

    veiculo meu_carro; // como usamos o typedef, agora não precisamos escrever: struct veiculo meu_carro;
    veiculo Luis_carro;

    meu_carro.marca= "Chevrolet"; // se declaramos a string como pointer, podemos atribuir valores 'diretamente' sem o strcpy
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

    // acessando a union data

    union Data data;

    printf("\n A memória ocupada por data é %d", sizeof(data)); // valor será igual ao da maior variável

    // acessando os membros de uma union

    data.i = 10;
    data.f = 220.5;
    strcpy( data.str, "C Programming");

    printf("\n data.i : %d", data.i);
    printf("\n data.f : %f", data.f);
    printf("\n data.str : %s", data.str);

    /*Podemos ver na impressão que os valores de i e f foram corrompidos porque o valor de str é o que está 'valendo' já que ele 
    foi o último a ser atribuído*/

    // agora vamos atribuir valores aos membros da union data um de cada vez

    data.i = 10;
    printf("\n data.i : %d", data.i);
   
    data.f = 220.5;
    printf("\n data.f : %.2f", data.f);
   
    strcpy( data.str, "C Programming");
    printf("\n data.str : %s", data.str);

    // vamos criar um arquivo de texto
    FILE *fp;
    char buff[240];

    // vamos usar fopen para abrir o arquivo test.txt 
    /* w+ significa que iremos abrir um arquivo de texto para leitura e escrita. 
    Primeiro, ele trunca o arquivo para comprimento zero, se existir, caso contrário, cria um arquivo se não existir.*/
    fp = fopen("/tmp/test.txt", "w+");
    fputc('A', fp); // escrever um único caracter no arquivo
    fputs("\n Testando fputs.", fp); // escrever uma string no aquivo
    fprintf(fp, "\n Testanto fprint. Float %.3f", 3.1415);
    fclose(fp); // fechando o arquivo

    // agora vamos abrir um arquivo existente e ver o que tem dentro

    fp = fopen("/tmp/test.txt", "r");

    buff[1] = fgetc(fp); // lê um único caracter
    printf("\n Primeiro caracter do arquivo: %c", buff[1]);

    fscanf(fp, "%s", buff); // lê até encontrar um espaço
    printf("\n 1 : %s", buff );

    fgets(buff, 240, (FILE*)fp); // lê até encontrar \n ou final do arquivo
    printf("\n 2: %s", buff );
   
    fgets(buff, 240, (FILE*)fp);
    printf("\n 3: %s", buff );
    fclose(fp);

    // vamos fornecer o valor de um caracter pelo teclado e depois imprimi-lo na tela
    int letra_2;
    printf("\n Digite um valor: ");
    letra_2 = getchar( );

    printf("\n Você digitou: ");
    putchar( letra_2 );
 
    // agora vamos entrar uma string e imprimir uma string
    char palavra2[100];
    printf("\n Digite um valor: ");
    fgets( palavra2, 100, stdin );

    printf("\n Você digitou: ");
    puts( palavra2 );

    // podemos usar fgets para entrar uma string de um arquivo
    FILE *ftxt;
    char palavra3[60];

    // abrindo arquivo
    ftxt = fopen("file.txt", "r");
    fgets(palavra3, 60, ftxt);
    puts(palavra3);
    // fechando arquivo
    fclose(ftxt);

    // a função scanf pega o que é digitado na tela de acordo com o formato especificado
    char palavra4[100];
    float num1;

    printf("\n Digite uma string seguida de um número: ");
    //Vamos ler uma string e um inteiro
    scanf("%s %f", palavra4, &num1);

    printf("Você digitou: %s %f.", palavra4, num1);

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
    printf("\n O fatorial de 13 é %.0f", fatorial(13));

    printf("\n Imprimindo sequência de Fibonacci \n");
    for (i = 0; i < 10; i++)
    {
        printf("%d \t", fibonacci(i));
    }
    

    // type casting interger to float
    int n1 = 10, n2 = 23;
    double n3;

    n3 = (double) n1 / n2;
    printf("\n O valor de n3 é %f: ",n3);

    // exemplo de integer promotion

    n2 = n1 + 'c';
    printf("\n O valor de n2 é: %d ", n2);

    n3 = n1 + 'c';
    printf("\n O valor de n3 é: %f \n", n3);

    //Avaliando função com argumentos variáveis

    printf("\n A média de 2, 3, 4, 5 = %f", average(4, 2,3,4,5));
    printf("\n A média de 5, 10, 15 = %f", average(3, 5,10,15));

    // vamos tentar abrir um arquivo inexistente para gerar uma mensagem de erro
    FILE * pf;
    int errnum;
    pf = fopen("unexist.txt", "rb"); 
	
    if (pf == NULL) {
   
       errnum = errno;
       fprintf(stderr, "\n Valor de errno: %d", errno);
       perror("\n Usando perror para imprimir a mensagem do erro: ");
       fprintf(stderr, "\n Usando strerror para retornar um pointer para a representação textual do erro: %s", strerror(errnum));
    } else {
   
       fclose (pf);
    }

    // erro para divisão por zero 
    int dividend = 20;
    int divisor = 0;
    int quotient;
  
    if( divisor == 0){
       fprintf(stderr, "\n Divisão por zero. Saindo ... \n");
       exit(EXIT_FAILURE);
    }
   
    quotient = dividend / divisor;
    fprintf(stderr, "\n O valor do quociente é: %d", quotient );

    exit(EXIT_SUCCESS);

    return 0;
}

int foo(int a) {  // implementando a função foo
    return a+1; // o valor de 'a' utilizado será o que está dentro do main
}

void print_big(int number){ //implementando a função print_big
    if(number > 10){
        printf("\n %d is big.",number);
    }
}