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

a,b,x=gets.chomp.split(' ').map{|n| n.to_f}

s = a * a
# 傾けてない状態でのcm
y = x / s.to_f

if a * b * a >= 2 * x
  h = 2 * x.to_f / (b * a)

  puts 90 - Math.atan(h / a) * 180 / Math::PI
else
  z = 2 * (b - y)
  puts 90 - Math.atan(z/a.to_f) * 180 / Math::PI
end