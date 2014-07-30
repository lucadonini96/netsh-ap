#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("wifi access point\n\n");
    int istr=0;
    bool flag=1;
    while(flag)
    {
       char nome[256],psw[256],comando[256];
       printf("Inserisci il codice dell'istruzione:\n0-status\n1-start\n2-stop\n3-cambia nome\n4-cambia password\n5-esci\n\n");
       scanf("%d",&istr);
       switch(istr)
       {
           case 0:
                system("netsh wlan show hostednetwork");
                break;
           case 1:
                system("netsh wlan start hostednetwork");
                break;
           case 2:
                system("netsh wlan stop hostednetwork");
                break;
           case 3:
                printf("inserisci il nuovo nome: ");
                //char[256] nome;
                scanf("%s",&nome);
                //char[256] comando;
                sprintf(comando,"netsh wlan set hostednetwork ssid=%s",nome);
                system(comando);
                system("netsh wlan start hostednetwork");
                break;
           case 4:
                printf("inserisci la nuova password (min 8 caratteri): ");
                //char[256] psw;
                scanf("%s",&psw);
                //char[256] comando;
                sprintf(comando,"netsh wlan set hostednetwork key=%s keyUsage=persistent",psw);
                system(comando);
                system("netsh wlan start hostednetwork");
                break;
           case 5:
                flag=0;
                break;                
       }
    }
}
                
                
