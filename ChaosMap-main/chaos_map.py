#deux code python un à mettre en commentaire et l'autre non si on souhaite avoir les valeurs extremes ou non, par défaut pas de valeurs extremes


# import numpy as np
# import matplotlib.pyplot as plt

# try:

#    euler = np.loadtxt('chaos_euler.csv', delimiter=',')
#    verlet = np.loadtxt('chaos_verlet.csv', delimiter=',')
#    yoshida = np.loadtxt('chaos_yoshida.csv', delimiter=',')
#    rk4 = np.loadtxt('chaos_rk4.csv', delimiter=',')

#    fig, axs = plt.subplots(2, 2, figsize=(14, 14))  # grille 2x2

#    axs[0][0].imshow(np.sqrt(euler.T + 1e-10), cmap='jet', origin='lower')
#    axs[0][0].set_title("Euler")

#    axs[0][1].imshow(np.sqrt(verlet.T + 1e-10), cmap='jet', origin='lower')
#    axs[0][1].set_title("Verlet")

#    axs[1][0].imshow(np.sqrt(yoshida.T + 1e-10), cmap='jet', origin='lower')
#    axs[1][0].set_title("Yoshida")

#    axs[1][1].imshow(np.sqrt(rk4.T + 1e-10), cmap='jet', origin='lower')
#    axs[1][1].set_title("RK4")
    
#    plt.tight_layout()
#    plt.show()

# except Exception as e:
#    print(f"Erreur : {e}")
import numpy as np
import matplotlib.pyplot as plt
def affiche_contraste(ax, data, titre):
    # On applique ta transformation (racine carrée) et on transpose
    data_transformee = np.sqrt(data.T + 1e-10)
    
    # On calcule les seuils pour forcer le contraste
    # Tu pourras modifier le '80' si tu veux encore plus ou un peu moins de contraste
    vmin = np.percentile(data_transformee, 5)
    vmax = np.percentile(data_transformee, 80)
    
    # On affiche avec vmin et vmax
    ax.imshow(data_transformee, cmap='jet', origin='lower', vmin=vmin, vmax=vmax)
    ax.set_title(titre)

try:
    # Chargement des fichiers
    euler = np.loadtxt('chaos_euler.csv', delimiter=',')
    verlet = np.loadtxt('chaos_verlet.csv', delimiter=',')
    yoshida = np.loadtxt('chaos_yoshida.csv', delimiter=',')
    rk4 = np.loadtxt('chaos_rk4.csv', delimiter=',')

    fig, axs = plt.subplots(2, 2, figsize=(14, 14))  # grille 2x2

    # Utilisation de la nouvelle fonction pour chaque carte
    affiche_contraste(axs[0][0], euler, "Euler")
    affiche_contraste(axs[0][1], verlet, "Verlet")
    affiche_contraste(axs[1][0], yoshida, "Yoshida")
    affiche_contraste(axs[1][1], rk4, "RK4")
    
    plt.tight_layout()
    plt.show()

except Exception as e:
    print(f"Erreur : {e}")
