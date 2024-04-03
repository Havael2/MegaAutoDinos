void definirLoja(int *lj) // Definição da loja a cada início de turno.
{
    int i;
    dinos bichosLoja[3];
    for (i=0; i<3; i++)
    {
        *(lj+i) = rand() % TAMesp;
        bichosLoja[i] = especies(lj+i);
    }
    printf("Bichos na loja:\n");
    for (i=0; i<3; i++) // Exibição dos bichos na loja.
    {
        printf("%d.%s  ", (i+1), bichosLoja[i].nome);
    }
}
