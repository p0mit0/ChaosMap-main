#deux code python un à mettre en commentaire et l'autre non si on souhaite avoir les valeurs extremes ou non, par défaut pas de valeurs extremes


# import numpy as np
# import matplotlib.pyplot as plt

# try:

#    euler = np.loadtxt('chaos_euler.csv', delimiter=',')
#    verlet = np.loadtxt('chaos_verlet.csv', delimiter=',')
#    yoshida = np.loadtxt('chaos_yoshida.csv', delimiter=',')
#    rk4 = np.loadtxt('chaos_rk4.csv', delimiter=',')

#    fig, axs = plt.subplots(2, 2, figsize=(14, 14), sharex=True, sharey=True)  # grille 2x2

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
def curtail(ax, data, titre):
    #racine carrée des valeurs, correction afin de compresser les valeurs extremes mais pas les plus faible
    data_transformee = np.sqrt(data.T + 1e-10)
    vmin = np.percentile(data_transformee, 5) #enleve les 5% plus faibles valeures
    vmax = np.percentile(data_transformee, 80) #enleve les 20% plus hautes valeures
    
    # vmin et vmax
    ax.imshow(data_transformee, cmap='jet', origin='lower', vmin=vmin, vmax=vmax)
    ax.set_title(titre)

# charge fichiers
euler = np.loadtxt('chaos_euler.csv', delimiter=',')
verlet = np.loadtxt('chaos_verlet.csv', delimiter=',')
yoshida = np.loadtxt('chaos_yoshida.csv', delimiter=',')
rk4 = np.loadtxt('chaos_rk4.csv', delimiter=',')

fig, axs = plt.subplots(2, 2, figsize=(14, 14), sharex=True, sharey=True) 
# curtail pour tronquer les valeurs extremes
curtail(axs[0][0], euler, "Euler")
curtail(axs[0][1], verlet, "Verlet")
curtail(axs[1][0], yoshida, "Yoshida")
curtail(axs[1][1], rk4, "RK4")
    
plt.tight_layout()
plt.show()