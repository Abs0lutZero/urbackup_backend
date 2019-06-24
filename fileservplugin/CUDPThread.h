#pragma warning ( disable:4005 )
#pragma warning ( disable:4996 )

#include "../Interface/Thread.h"
#include "types.h"
#include "socket_header.h"
#include <string>


class CUDPThread : public IThread
{
public:
	CUDPThread(_u16 udpport, std::string servername, bool use_fqdn);
	~CUDPThread();

	std::string getServername();

	void operator()(void);

	bool hasError(void);
	void stop(void);
private:
	void init(_u16 udpport,std::string servername, bool use_fqdn);

	bool init_v4(_u16 udpport);

	bool init_v6(_u16 udpport);

	SOCKET udpsock;
	SOCKET udpsockv6;
	std::string mServername;

	bool UdpStep(void);

	bool use_fqdn_;
	_u16 udpport_;

	bool has_error;
	volatile bool do_stop;
};

std::string getSystemServerName(bool use_fqdn);
