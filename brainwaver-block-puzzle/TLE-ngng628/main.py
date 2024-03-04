#!/usr/bin/env python3

from random import randint
from copy import deepcopy
import itertools

class Dice:
   UP    = 0
   DOWN  = 1
   RIGHT = 2
   LEFT  = 3
   FWD   = 4
   BACK  = 5

   def __init__(self, x, y, udrlfb):
      self.x = x
      self.y = y
      self.f = udrlfb

   def rotate(self, id):
      if id == self.LEFT:
         self._swap(self.UP, self.RIGHT)
         self._swap(self.RIGHT, self.DOWN)
         self._swap(self.DOWN, self.LEFT)
         self.x -= 1
      elif id == self.RIGHT:
         self._swap(self.UP, self.LEFT)
         self._swap(self.LEFT, self.DOWN)
         self._swap(self.DOWN, self.RIGHT)
         self.x += 1
      elif id == self.FWD:
         self._swap(self.UP, self.BACK)
         self._swap(self.BACK, self.DOWN)
         self._swap(self.DOWN, self.FWD)
         self.y -= 1
      elif id == self.BACK:
         self._swap(self.UP, self.FWD)
         self._swap(self.FWD, self.DOWN)
         self._swap(self.DOWN, self.BACK)
         self.y += 1

      return self.f[self.DOWN]


   def arrange(self, id1, tar1, id2, tar2):
      while self.f[id1] != tar1 or self.f[id2] != tar2:
         r = randint(0, 2)
         self.rotate(r)


   @staticmethod
   def Id(c):
      if c == 'U': return Dice.Up
      elif c == 'D': return Dice.Down
      elif c == 'R': return Dice.Right
      elif c == 'L': return Dice.Left
      elif c == 'F': return Dice.Fwd
      elif c == 'B': return Dice.Back
      assert False


   @staticmethod
   def Rev(c):
      if c == 'U': return 'D'
      elif c == 'D': return 'U'
      elif c == 'R': return 'L'
      elif c == 'L': return 'R'
      elif c == 'F': return 'B'
      elif c == 'B': return 'F'
      assert False


   def _swap(self, i, j):
      self.f[i], self.f[j] = self.f[j], self.f[i]

sx, sy, gx, gy = map(int, input().split())
dice = Dice(sx, sy, ['mark', '1', '2', '3', '4', '5'])
ans = []
while dice.x != gx or dice.y != gy:
   if dice.x < gx:
      ans.append('R')
      dice.rotate(Dice.RIGHT)
   if dice.y < gy:
      ans.append('U')
      dice.rotate(Dice.BACK)
   if dice.x > gx:
      ans.append('L')
      dice.rotate(Dice.LEFT)
   if dice.y > gy:
      ans.append('D')
      dice.rotate(Dice.FWD)


if dice.f[Dice.DOWN] == 'mark':
   print(len(ans))
   for i in ans:
      print(f'{i} 1')

   exit()


op_to_char = {
   Dice.BACK: 'U',
   Dice.LEFT: 'L',
   Dice.RIGHT: 'R',
   Dice.FWD: 'D',
}

for op1 in itertools.permutations([Dice.FWD, Dice.RIGHT, Dice.BACK, Dice.LEFT]):
   d = Dice(dice.x, dice.y, deepcopy(dice.f))
   for op in op1:
      d.rotate(op)

   if d.f[Dice.DOWN] == 'mark':
      ans1 = [op_to_char[op] for op in op1]
      print(len(ans) + 4)
      for i in ans + ans1:
         print(f'{i} 1')
      exit()

   for op2 in itertools.permutations([Dice.FWD, Dice.RIGHT, Dice.BACK, Dice.LEFT]):
      d2 = Dice(d.x, d.y, deepcopy(d.f))
      for op in op2:
         d2.rotate(op)
      if d2.f[Dice.DOWN] == 'mark':
         ans1 = [op_to_char[op] for op in op1]
         ans2 = [op_to_char[op] for op in op2]
         print(len(ans) + 8)
         for i in ans + ans1 + ans2:
            print(f'{i} 1')
         exit()

print('None')
