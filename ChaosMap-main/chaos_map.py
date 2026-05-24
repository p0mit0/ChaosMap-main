import numpy as np
import matplotlib.pyplot as plt

try:
    # Chargement avec tes nouveaux noms de fichiers
    euler = np.loadtxt('chaos_euler.csv', delimiter=',')
    verlet = np.loadtxt('chaos_verlet.csv', delimiter=',')
    yoshida = np.loadtxt('chaos_yoshida.csv', delimiter=',')
    rk4 = np.loadtxt('chaos_rk4.csv', delimiter=',')

    fig, axs = plt.subplots(2, 2, figsize=(14, 14))  # grille 2x2

    axs[0][0].imshow(np.sqrt(euler.T + 1e-10), cmap='jet', origin='lower')
    axs[0][0].set_title("Euler")

    axs[0][1].imshow(np.sqrt(verlet.T + 1e-10), cmap='jet', origin='lower')
    axs[0][1].set_title("Verlet")

    axs[1][0].imshow(np.sqrt(yoshida.T + 1e-10), cmap='jet', origin='lower')
    axs[1][0].set_title("Yoshida")

    axs[1][1].imshow(np.sqrt(rk4.T + 1e-10), cmap='jet', origin='lower')
    axs[1][1].set_title("RK4")
    
    plt.tight_layout()
    plt.show()

except Exception as e:
    print(f"Erreur : {e}")

