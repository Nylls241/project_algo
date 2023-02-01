# project_algo
Rummikub 

#commande pour compiler le code source :

- make , pour compiler .Il se crée un fichier exécutable prog que vous pouvez exécuter par la suite . Puis faite un make clean pour virer les fichiers objets.

- gcc main.c init.c dessin_rendu1.c input.c destroy.c $(sdl2-config --cflags --libs) ; celà sert à compiler la fenêtre principale du projet (Implémentation du Rummikub) . NB : vous devez être dans le dossier src du projet pour que cette commande marche .

