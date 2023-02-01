# project_algo

https://github.com/Nylls241/project_algo.git

Rummikub est le jeu à réaliser dans ce projet .Nous le codons en C avec la biliothèque SDL2. Pour jouer au Rummikub, il vous faut :
2 à 4 joueurs.
52 tuiles sur lesquelles sont inscrits des chiffres de 1 à 13. Les chiffres peuvent être de couleurs jaune, rouge,
orange ou bleu.
4 tuiles joker sur lesquelles apparaît le visage d’un bonhomme coloré (un joker orange , jaune , rouge et bleu) . Ces tuiles vous permettront deremplacer n’importe qu’elle autre tuile.
4 chevalets pour poser vos tuiles.Le but du jeu
Être le premier à poser toutes ses plaques en formant des combinaisons de chiffres de la manière la plus judicieuse.
Pour commencer la partie, chaque joueur pioche 14 tuiles qu’il pose ensuite sur son chevalet.
Afin de déterminer qui commencera, chaque joueur pioche une tuile. C’est celui qui aura le plus grand chiffre qui
débutera.
Pour qu’un joueur puisse débuter, il faut que la ou les combinaisons qu’il dépose sur la table valent 30 points minimum.
Si ce n’est pas le cas, le joueur pioche une tuile et c’est au tour d’un autre joueur.
Il sera peut-être obligé de piocher plusieurs tours avant de pouvoir poser ces tuiles.
Vous allez essayer de vous débarrassez de vos tuiles soit en créant une combinaison, à condition que le nombre de tuile
soit de 3 minimum, soit en complétant ou modifiant les combinaisons déjà posées sur le plateau de jeu.
Vous pouvez aussi utiliser vos tuiles de façons différentes :
• Si un joueur à utiliser un joker dans sa combinaison vous pouvez le récupérer en positionnant la tuile qu’il
remplaçait. ATTENTION le joker doit être utilisé immédiatement dans une autre combinaison.
• Vous pouvez également rajouter une tuile à l’extrémité d’une combinaison de façon à récupérer la tuile qui se
trouve à l’autre extrémité. (Exemple : La suite 234 est posée, positionnez le 1 et ainsi vous pouvez retirer le 4
afin de l’utiliser immédiatement dans une autre combinaison).
• Si vous souhaitez utiliser une tuile déjà positionnée dans une combinaison vous pouvez mais vous devez
absolument la remplacer par une autre tuile.
• Vous pouvez également diviser en deux une suite déjà positionnée. (Exemple : Si la suite 678910 est sur la
table, vous pouvez la séparer en 678 et rajouter le 11 et créer la suite 91011.)
• Si une combinaison comporte plus de 3 tuiles vous pouvez en retirer une afin de l’utiliser.
Le joueur qui pose le plus rapidement ses tuiles gagne la partie.
Les autres joueurs doivent donc additionner les points restant sur leur chevalet. Ces points seront des points négatifs. Un
joker qui reste sur votre chevalet vous coûtera 30 points négatifs.


# commande pour compiler le code source :

- make , pour compiler .Il se crée un fichier exécutable prog que vous pouvez exécuter par la suite . Puis faite un make clean pour virer les fichiers objets. NB: commande à excuter en étant dans le dossier du projet (projet_algo) . Si cela ne marche pas faite celle-ci à la place . 

- gcc main.c init.c dessin_rendu1.c input.c destroy.c $(sdl2-config --cflags --libs) ; celà sert à compiler la fenêtre principale du projet (Implémentation du Rummikub) . NB : vous devez être dans le dossier src du projet pour que cette commande marche .

# installation de la SDL2 :

 Un conseil faite le sur une machine linux , pour ne pas avoir trop de mal . Voici la commande d'installation sur linux  :
  sudo apt-get install libsdl2-dev. Pour ce qui ne sont pas sous linux , télécharger une machine virtuel (virtualbox par exemple) , toutefois il est possible d'installer la SDL sur d'autre système que linux , mais bon c'est un peu compliqué bizarement .Nous avons essayé de rendre notre projet dynamique de telle sorte qu'une autre machine est besoin d'installer la SDL , mais élasse nous n'avons pas réussi , c'est possible commencez par çà si vous volez avancez sans plus vite sans problème ,en tout cas au niveau de l'entête de la SDL. 
  
  # Fonctions principales devélopper au cours du projet (aspect frontend) :
   - initSDL() ; qui initialise la SDL , en chargeant l'affichage de la fenêtre et le rendu 
   - prepareScene(application app) ; qui donne un fond bleu à notre fenêtre et rendu , c'est cette couleur avec quoi dessinera tout , il prend en paramètre une variable app de type application (c'est une structure définie dans le fichier structure.h du dossier include) .
   - dessin_plateau(application app) ; nous renvoie un plateau avec un chevalet .
   - dessin_chevalet(application app) ; nous renvoie le chevalet sur quoi déposera les tuiles  
   - dessin_tuile(application app ,int nb) ; pour nous servir mettre nos tuiles dans le chevalet , ici cette fonction à un 2ème paramètre nb , pour le nombre de tuile à piocher .
