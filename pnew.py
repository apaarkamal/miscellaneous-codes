import pygame
import sys

pygame.init()

WIDTH = 800
HEIGHT = 600

screen = pygame.display.set_mode((WIDTH,HEIGHT))

game_over = False

while not game_over:
	for event in pygame.event.get():

		if event.type == pygame.QUIT:
			game_over = True
pygame.quit()


