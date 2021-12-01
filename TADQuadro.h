#ifndef TADQUADRO_H_INCLUDED
#define TADQUADRO_H_INCLUDED

typedef struct{
    char quadro[20][80];
}TipoQuadro;

void Inicializa(TipoQuadro *Quad);
void ImprimeArt(TipoQuadro *Quad);
int SubMenu();
void Inicializa(TipoQuadro *Quad);
void AsteriscoArt(TipoQuadro *Quad, int qtd,short flag);
void MaisArt(TipoQuadro *Quad, int qtd,short flag);
void XArt(TipoQuadro *Quad, int qtd,short flag);
void AleatorioArt(TipoQuadro *Quad, int qtd,short flag);
void CruzArt(TipoQuadro *Quad, int qtd,short flag);

#endif // TADQUADRO_H_INCLUDED
