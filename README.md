#*BUGS CONHECIDOS*

##1.
### Durante a alocação de um dinossauro comprado, com a excessão da primeira alocação, 
### escolha sempre uma posição já ocupada por outro dinossauro ou uma posição adjacente 
### a outra já ocupada. Do contrário, o dinossauro comprado desaparecerá, não sendo alocado
### em lugar algum.

##2.
# Algumas vezes, o programa não consegue rodar a função batalha, devido a um erro
### de segmentação (segmentation fault (core dumped)). Caso ocorra, reinicie a execução.
### Isso ocorre provavelmente por conta de uma falha na composição do grupo de dinossauros
### do bot adversário, gerando algum elemento NULL. Será corrigido nas próximas versões. 
