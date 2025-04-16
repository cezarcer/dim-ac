# Dim-ac

Informações gerais:
Dimensionamento de ar-comprimido (dim-ac) é um aplicativo em linha de comando para cálculo de dimensionamento de linhas de ar-comprimido baseado em nos seguintes parametros:
Tamanho da linha em métros;
Volume do fluxo de ar em m³/h;
Queda de pressão esperada em bar;
Pressão de trabalho na linha;
Os componentes da linha, como curvas, T's, valvulas etc.

Totalmente escrito em C com os dados retirados de:

Parker, Dimensionamento de Redes de Ar Comprimido, Apostila M1004 BR, Parker Hannifin Corporation, 2006

Fialho, A.B, Automação Pneumática: Projetos, dimensionamento e análise de circuitos, Érica, 2003.

Local dos dados;
Os dados tabelados se encontram em opt/dim-ac/dados;

Caso mude o local dos arquivos deve mudar também o local no arquivo func-tubos.c 

Procedimento de instalação:


Como reportar problemas:
Os bugs devem ser reportados ao sistema de rastreamento de problemas do GitHub:

https://github.com/cezarcer/dim-ac/issues

Você precisará criar uma conta.

No relatório de bug, inclua:

Informações sobre o seu sistema. Por exemplo:

Qual sistema operacional e versão
Qual versão do X
Para Linux, qual versão da biblioteca C
E qualquer outra informação que você considere relevante. 

Por exemplo:
Como reproduzir o bug.

Se o bug foi uma falha, o texto exato que foi impresso quando a falha ocorreu.

Patches:
Patches devem ser enviados para https://github.com/cezarcer/dim-ac, preferencialmente via pull requests.

Grato Cezar C.
