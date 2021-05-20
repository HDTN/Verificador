//Verifcador de RG
int primeiroD, segundoD, terceiroD, quartoD, quintoD, sextoD, setimoD, oitavoD, nonoD,decimoD,decimoPrimeiroD, verificacao;
char a, b, c, d, e, f, g, h, i, j, k;
String rg,cpf,escolhaUsuario;
void setup() {
  Serial.begin(9600);
}
void loop() {
  //APRESENTACAO DO SISTEMA
  Serial.println("Ola, seja bem vindo ao sistema de validacao de documentos do grupo ALPHA");
  //Delay utilizado para melhorar a experiencia do usuario
  delay(2000);
  while(escolhaUsuario !="3"){
  Serial.println("Digite 1 - Para validar seu RG");
  Serial.println("Digite 2 - Para validar seu CPF");
  Serial.println("Digite 3 - Para encerrar o funcionamento");
  while(Serial.available()==0);
  escolhaUsuario = Serial.readString();
  if(escolhaUsuario =="1"){
    Serial.println("Digite o seu RG (somente numeros):");
    while(Serial.available()==0);
    rg = Serial.readString();
    if(validaRg(rg))
     Serial.println("RG valido.");
    else
     Serial.println("RG invalido.");  
  }else if(escolhaUsuario =="2"){
    Serial.println("Digite o seu CPF (somente numeros):");
    while(Serial.available()==0);
    cpf = Serial.readString();
    if(validaCpf(cpf))
      Serial.println("CPF valido.");
    else
      Serial.println("CPF invalido.");  
  }else if(escolhaUsuario != "3")
    Serial.println("Digite novamente, escolha invalida");
  }
  Serial.println("Obrigado por utilizar nosso sistema");
  Serial.println(":)");
  while(1);
}



bool validaRg(String rg){
  if(rg.length()!=9||rg=="000000000"||rg=="111111111"||rg=="222222222"||rg=="333333333"||rg=="444444444"||rg=="555555555"||rg=="666666666"||
  rg=="777777777"||rg=="888888888"||rg=="999999999")
    return false;
 // destrinchar a string em caracteres
  a=rg.charAt(0); 
  b=rg.charAt(1); 
  c=rg.charAt(2); 
  d=rg.charAt(3); 
  e=rg.charAt(4); 
  f=rg.charAt(5); 
  g=rg.charAt(6); 
  h=rg.charAt(7); 
  i=rg.charAt(8); 
 // transformar em números inteiros 
  primeiroD=a-'0';
  segundoD=b-'0';
  terceiroD=c-'0';
  quartoD=d-'0';
  quintoD=e-'0';
  sextoD=f-'0';
  setimoD=g-'0';
  oitavoD=h-'0';
  nonoD=i-'0';
  // printar o rg descrito na tela
  Serial.print("RG: ");
  Serial.print(primeiroD);
  Serial.print(segundoD);
  Serial.print(".");
  Serial.print(terceiroD);
  Serial.print(quartoD);
  Serial.print(quintoD);
  Serial.print(".");
  Serial.print(sextoD);
  Serial.print(setimoD);
  Serial.print(oitavoD);
  Serial.print("-");
  if(nonoD==72){ // se o nono dígito corresponder a 72 o mesmo será "x"
    Serial.println("x");
  }else{
  Serial.println(nonoD);
  }
  verificacao = ((primeiroD*2) + (segundoD*3) + (terceiroD*4) + (quartoD*5) + (quintoD*6) + (sextoD*7) + (setimoD*8) + (oitavoD*9)) % 11;
  verificacao = 11 - verificacao;
  // verificar se o rg digitado é válido
  if(verificacao==nonoD||(verificacao==10&&nonoD==72)||(verificacao==11&&nonoD==0))
    return true;
  return false;
  
}

bool validaCpf(String cpf){
  if(cpf.length()!=11||cpf=="00000000000"||cpf=="11111111111"||cpf=="22222222222"||cpf=="33333333333"||cpf=="44444444444"||cpf=="55555555555"||cpf=="66666666666"||
  cpf=="77777777777"||cpf=="88888888888"||cpf=="99999999999")
    return false;
  // destrinchar a string em caracteres
  a=cpf.charAt(0);
  b=cpf.charAt(1); 
  c=cpf.charAt(2);
  d=cpf.charAt(3); 
  e=cpf.charAt(4); 
  f=cpf.charAt(5); 
  g=cpf.charAt(6); 
  h=cpf.charAt(7);
  i=cpf.charAt(8); 
  j=cpf.charAt(9); 
  k=cpf.charAt(10); 
 // transformar em números inteiros 
  primeiroD=a-'0';
  segundoD=b-'0';
  terceiroD=c-'0';
  quartoD=d-'0';
  quintoD=e-'0';
  sextoD=f-'0';
  setimoD=g-'0';
  oitavoD=h-'0';
  nonoD=i-'0';
  decimoD=j-'0';
  decimoPrimeiroD=k-'0';
  // printar o rg descrito na tela
  Serial.print("CPF: ");
  Serial.print(primeiroD);
  Serial.print(segundoD);
  Serial.print(terceiroD);
  Serial.print(".");
  Serial.print(quartoD);
  Serial.print(quintoD);
  Serial.print(sextoD);
  Serial.print(".");
  Serial.print(setimoD);
  Serial.print(oitavoD);
  Serial.print(nonoD);
  Serial.print("-");
  Serial.print(decimoD);
  Serial.println(decimoPrimeiroD);


   //Se for 0 ou 1, o decimo dígito é [0] (zero). Se for 2, 3, 4, 5, 6, 7, 8, 9 ou 10, o dígito J é [11 - RESTO]
  verificacao = ((primeiroD*10) + (segundoD*9) + (terceiroD*8) + (quartoD*7) + (quintoD*6) + (sextoD*5) + (setimoD*4) + (oitavoD*3) +(nonoD*2)) % 11;
  if(verificacao ==0 || verificacao ==1){
    decimoD =0;
  }
  else{
    decimoD =11 - verificacao;
  }
  
  //Se for 0 ou 1, o decimo primeiro dígito K é [0] (zero). Se for 2, 3, 4, 5, 6, 7, 8, 9 ou 10, o dígito K é [11 - RESTO].  
  verificacao = ((primeiroD*11) + (segundoD*10) + (terceiroD*9) + (quartoD*8) + (quintoD*7) + (sextoD*6) + (setimoD*5) + (oitavoD*4) +(nonoD*3)+ (decimoD*2)) % 11;
    if(verificacao ==0 || verificacao ==1){
    decimoPrimeiroD =0;
  }else{
    decimoPrimeiroD = 11 - verificacao;
  }

  int p = j-'0';
  int q = k-'0';
  
  if(decimoD == p && decimoPrimeiroD == q)
    return true;
  return false;
}