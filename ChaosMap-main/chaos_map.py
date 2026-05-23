import numpy as np
import matplotlib.pyplot as plt

try:
    # Chargement avec tes nouveaux noms de fichiers
    euler = np.loadtxt('chaos_euler.csv', delimiter=',')
    verlet = np.loadtxt('chaos_verlet.csv', delimiter=',')
    yoshida = np.loadtxt('chaos_yoshida.csv', delimiter=',')

    fig, axs = plt.subplots(1, 3, figsize=(18, 11))
   
    # LIGNE DU HAUT : NORMALISÉ (0 à 1)
    im1=axs[0].imshow(np.sqrt(euler.T + 1e-10), cmap='inferno', origin='lower')
    axs[0].set_title("Euler")
   
    im2=axs[1].imshow(np.sqrt(verlet.T + 1e-10), cmap='inferno', origin='lower')
    axs[1].set_title("Verlet")

    im3=axs[2].imshow(np.sqrt(yoshida.T + 1e-10), cmap='inferno', origin='lower')
    axs[2].set_title("Yoshida")

    
    plt.tight_layout()
    plt.show()

except Exception as e:
    print(f"Erreur : {e}")

