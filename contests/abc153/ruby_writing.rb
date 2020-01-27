require 'pp'
require 'prime'
require 'set'

# N=gets.chomp.split(' ').map{|n| n.to_i}.first
#
# if Prime.prime?(N)
#   puts N-1
#   exit
# end
#
# a=0
# b=0
#
# mini = 1_000_000_000_000_0
# source = Math.sqrt(N).to_i+1
# 1.upto(source) do |n|
#   next if N%n!=0
#   a=n
#   b=N/n
#   if ((a-1 + b-1) < mini)
#     mini = a-1 + b-1
#   end
# end
#
# puts mini
#
#
#

N,K=gets.chomp.split(' ').map{|n| n.to_f}
A=gets.chomp.split(' ').map{|n| n.to_i}

puts A.combination(K).map{|a| a.max - a.min}.inject(:+)%((10**9) + 7)