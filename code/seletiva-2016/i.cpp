#include <cstdio>
#include <cstring>

using namespace std;

		/*switch(instrucao) {
			case ADD:
			case SUB:
			case MUL:
			case DIV:
			case AND:
			case OR:
			case XOR:
			case GOTOIF:
			case HALT:
		}*/
#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3
#define AND 4
#define OR 5
#define XOR 6
#define GOTOIF 7
#define HALT 8

#define reg(a) ((a)&0xFF)

int vis[101][256];
int inst[101][3];
int N;

int main () {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int n, instrucao;
		char label[101];
		scanf("%d %s", &n, label);
		if (strcmp(label, "add") == 0) instrucao = ADD;
		else if (strcmp(label, "sub") == 0) instrucao = SUB;
		else if (strcmp(label, "mul") == 0) instrucao = MUL;
		else if (strcmp(label, "div") == 0) instrucao = DIV;
		else if (strcmp(label, "and") == 0) instrucao = AND;
		else if (strcmp(label, "or") == 0) instrucao = OR;
		else if (strcmp(label, "xor") == 0) instrucao = XOR;
		else if (strcmp(label, "gotoif") == 0) instrucao = GOTOIF;
		else if (strcmp(label, "halt") == 0) instrucao = HALT;

		int a1, a2;
		switch(instrucao) {
			case ADD:
			case SUB:
			case MUL:
			case DIV:
			case AND:
			case OR:
			case XOR:
				inst[n][0] = instrucao;
				scanf("%d", &a1);
				inst[n][1] = a1;
				break;
			case GOTOIF: 
				inst[n][0] = instrucao;
				scanf("%d %d", &a1, &a2);
				inst[n][1] = a1;
				inst[n][2] = a2;
				break;
			case HALT:
				inst[n][0] = instrucao;
				break;
		}
	}
	// fin leitura
	unsigned char R = 0, fim = 0, pc = 1;
	int C = 0;
	while (1) {
		if (!vis[pc][R]) {
			C++;
			// processa inst
			vis[pc][R] = 1;
			switch(inst[pc][0]) {
				case ADD:
					R += inst[pc][1];
					pc++;
					break;
				case SUB:
					R -= inst[pc][1];
					pc++;
					break;
				case MUL:
					R *= inst[pc][1];
					pc++;
					break;
				case DIV:
					R /= inst[pc][1];
					pc++;
					break;
				case AND:
					R &= inst[pc][1];
					pc++;
					break;
				case OR:
					R |= inst[pc][1];
					pc++;
					break;
				case XOR:
					R ^= inst[pc][1];
					pc++;
					break;
				case GOTOIF:
					if (R >= inst[pc][1]) pc = inst[pc][2];
					else pc++;
					break;
				case HALT:
					fim = 1;
					break;
			}
			if (fim == 1) break;
		} else break;
	}
	if (fim == 1) printf("%d\n", R);
	else printf("execucao infinita\n");
	return 0;
}
