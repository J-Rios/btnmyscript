#include <stdio.h>
#include <wiringPi.h>

#define P_BTN_PWR    24
#define P_BTN_RUN    25
#define WAIT_NPRES   100
#define WAIT_PRES    3000
#define MAX_CMD_LINE 128
 
int main(int argc, char* argv[])
{
	int run = 0;
	char script[MAX_CMD_LINE];
	
	if(argc == 2) // Se ha llamado a la funcion con un argumento
	{		
		// Configurar WiringPi y los pines de los pulsadores como entradas
		wiringPiSetup();
		pinMode(P_BTN_PWR, INPUT);
		pinMode(P_BTN_RUN, INPUT);
		
		while(1)
		{
			// Boton de lanzar/parar el script especifico
			if(digitalRead(P_BTN_RUN) == LOW)
			{
				if(run == 0) // Script no ejecutandose, lanzarlo
				{
					run = 1;
					snprintf(script, MAX_CMD_LINE, "./run_mysh.sh %s", argv[1]);
					system(script);
					delay(WAIT_PRES);
				}
				else // Script ejecutandose, pararlo (cerrarlo)
				{
					run = 0;
					snprintf(script, MAX_CMD_LINE, "./stop_mysh.sh %s", argv[1]);
					system(script);
					delay(WAIT_PRES);
				}
			}
			
			// Boton de apagado presionado, lanzar el script de apagado del sistema
			if(digitalRead(P_BTN_PWR) == LOW)
				system("shutdown -h now");
			
			delay(WAIT_NPRES);
		}
	}
	else // Ningún o demasiados argumentos proporcionados
		printf("\n\nIncorrect call of the script. You must specify an argument (i.e. myscript blink)\n\n");
	
    return 0;
}