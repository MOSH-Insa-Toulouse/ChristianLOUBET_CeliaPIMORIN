# Projet_MOSH 

# 1. Introduction

Le 25 janvier 2021, nous avons commencé le projet «du capteur au banc de test en open source hardware», ce projet a pour but de vérifier la viabilité de la technologie des capteurs électronique à base de papier. Les capteurs à base papier peuvent être utilisé comme jauges de contrainte pour détecter les déformations: de compression et de traction. Ces capteurs peuvent être fabriqué sans électrodes métalliques en utilisant seulement le graphite issu des crayons à papier. Afin de tester nos capteurs nous avons réalisé notre banc de test et nous exploitons nos capteurs avec un circuit imprimé connecté à une Shield Arduino, ce montage transmet par Bluetooth nos mesures vers l’application APK, nous utilisons cette application sur nos smartphones. 

# 2. Capteur Graphite

La résistance du capteur graphite: Sur le papier est déposé du graphite, des atomes de carbones sont donc à la surface du papier, il y a une distance a entre chacun des atomes. Quand le capteur subit une déformation, sa longueur L s’agrandit/diminue et il en va de même pour la distance a entre les atomes. La déformation du capteur papier fait varier la résistance du capteur, car la longueur du capteur et la distance entre les atomes varie elle aussi. La sensibilité du capteur est très grande car elle dépend de l'effet tunnel qui dépend exponentiellement de la ditance entre le particules. Nos capteurs papier ont une zone nominale d’emploi, il ne faut pas trop déformer les capteurs(la déformation ne doit dépasser les 1 %).Les mines de crayon les plus dures(9H, 7H, 5H...) contiennent une proportion plus élevée de colle argileuse tandis que les mines les plus molles (5B,7B, 9B...) ont une proportion de particules de graphite, moins il y a de graphite sur le papier et plus la résistance du capteur augmente. 

Le principe physique du capteur repose sur les systèmes granulaires. Un système granulaire est un système avec des grains de tailles nanométrique où la conductance intragrain est très grande devant la conductance intergrain. En effet la conductance inter grain est la conductance entre deux particules et la conductance intragrain dépend de la diffusivité de la particule quantique qui depend de l'espacement entre les niveaux d'énergie. 
La conductance dans un système granulaire dépend de la constante de barrière tunnel, l'interdistance, l'energie de chargement et de la température.

# 2. La Shield PCB 



# 3. Le code Arduino pour le module bluetooth et l'écran OLED
# 4. Le code Android APK 
# 5. Le Protocol pour le banc de test

Au début nous déformions notre capteur avec un banc de test cylindrique mais nous avions des mesures aberrantes, c’est en montrant nos résultats à notre professeur que nous avons compris l’origine du problème: les rayons de courbure du cylindre sont trop grands et cela fait dépasser la zone nominale d’emploi de nos capteurs. Sur conseil de Monsieur Grisolia, nous avons utilisé un autre banc de test: avec du ruban adhésif, nous fixons les pinces du capteur sur le bord d’une table, nous mettions une règle sous l’extrémité du capteur qui dépasse de la table. Avec la règle nous déformions le capteur, nous la faisions glisser très légèrement vers le haut. Cela permet de mieux contrôler la déformation du capteur.

# 6. La Datasheet du Capteur graphite
