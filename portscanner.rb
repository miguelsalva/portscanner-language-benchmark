#! /usr/bin/ruby

require 'socket'
require 'timeout'

$site = ARGV[0]
$min_port = 0 
$max_port = 65535
$puertos = ((Integer $min_port)..(Integer $max_port)).to_a

def scanport(port)
    s = Socket.new Socket::AF_INET, Socket::SOCK_STREAM
	begin
		sockaddr = Socket.pack_sockaddr_in(port, $site)
	rescue
		puts "Target error, could not resolve"
		exit
	end
		begin
			@result = s.connect(sockaddr)
		rescue
			return false
		end
	if @result == 0 
		return true
	else
		return false
	end
end

puts "Start scan... \n\n"
$puertos.each do |port|
	if scanport(port)
		puts "Port" + port.to_s + ": Open"
	end
end

puts "\n Scan finished"
