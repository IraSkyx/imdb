## IMDb

### Descriptif

IMDb permet de consulter une fraction des films IMDb cultes de la plateforme ainsi que les plus grands acteurs de ces films sous forme de Master-Detail.

### Techniques de programmation utilisées

### Accès BDD (SQLite)

Les données proviennent d'un fichier dump SQLite qui contient deux tables *movies* et *actors*.

#### QObject avec QProperties

Chaque entité Movie et Actor est un QObject avec plusieurs QProperties. La modification d'une des propriétés entraîne son rafraîchissement dans les listes.

#### ListView partiellement éditable + Modèle C++ + Tri + Recherche

Les listes de Movies et d'Actors s'appuient sur un modèle C++ qui contient une liste de QObject. 

Elles sont éditables dans le Detail en utilisant le Push Up Menu et en cliquant sur Edit.

Les listes sont triées par défaut par titre pour les films et par nom pour les acteurs. La recherche est aussi basée sur ces critères.

#### PullDownMenu

Un PullDownMenu est présent dans le Master des Movies et des Actors, il permet de montrer les pages de navigation disponibles.

#### Clic

Un clic sur un Movie/Actor ouvre la page de detail.

#### PushUpMenu

Un PushUpMenu est présent dans le Detail des Movies et des Actors, il permet de montrer les options disponibles dans le Detail. Il contient un button qui redirige vers la page d'Edit

### Detail: Edit

Le Movie/Actor est éditable. L'édition d'un champ notifie le modèle de ses changements.

#### Favoris (QSettings)

Un button pour ajouter/supprimer des favoris est présent sur chaque élément du Master. Nous utilisons QSettings pour sauvegarder les favoris d'une exécution à l'autre.
