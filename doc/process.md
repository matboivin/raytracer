- Parser scène -> remplir structure
lire+parse+check en même temps  
Un read + une fonction qui check+parse dans cette fonction faire tableau pointeurs ou un parser récursif https://en.m.wikipedia.org/wiki/Recursive_descent_parser

Le Ray tracing procède de la caméra vers les sources de lumière.

- Si 2e argument --save
  - Sauver l'image en bmp et exit

- Sinon rendre la scène dans une fenêtre

- Lancer un rayon depuis la caméra
- Premier point d'impact du rayon sur un objet
  - Définir cet objet
    - Lancer rayons depuis ce point d'impact vers chaque source de lumière
      - Objet est éclairé ou à l'ombre ?
    - Combiner luminosité avec propriétés de la surface
      - Couleur ?
      - Texture ?
      - Transparence ?
      - Réflexion ?
    - Obtenir couleur finale du pixel

- Gérer les events

- Si plus d'une caméra, alterner entre les caméras à l'aide d'un keybind
- ESC ou croix rouge pour fermer la fenêtre et exit proprement
