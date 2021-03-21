from tcp_server import TCPServer
import threading
import sys

class TCPServerMultiClient(TCPServer):
    def __init__(self, host, port):
        super().__init__(host, port)

    def wait_for_client(self):
        try:
            self.print_with_time('🔄 Listening for incoming connection...')
            self.sock.listen(10)

            while True:
                client_sock, client_address = self.sock.accept()
                self.print_with_time(f'🤝 Accepted connection from {client_address}')
                c_thread = threading.Thread(target = self.handle_client,
                                        args = (client_sock, client_address))
                c_thread.start()
        except KeyboardInterrupt:
            self.shutdown_server()

if __name__ == '__main__':
    if len(sys.argv) == 1:
        print("Usage: python server.py [ port_no (int) ]")
        sys.exit()
    else:
        port = int(sys.argv[1])
    tcp_server = TCPServerMultiClient('127.0.0.1', port)
    tcp_server.configure_server()
    tcp_server.wait_for_client()