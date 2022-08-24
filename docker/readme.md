## Docker normally used command

### Start & Help

**start docker**  : `systemctl start docker`  

**stop docker**   : `systemctl stop docker`

**restart docker**: `systemctl restart docker`  

**check docker**  : `systemctl status docker`  

**power on VM with docker** : `systemctl enable docker`  

**see docker info**         : `docker info`  

**see docker general help** : `docker --help`  

**see specific command help**  : `deocker [command] --help`  

### Image

**list all images**: `docker images`  

**search images in repo**: `docker search [name] --limit [number of results]`  

**download from repo**:  
&nbsp;&nbsp;&nbsp;&nbsp; `docker pull [image name]`   This command will download latest version equal to `docker pull [image name]:latest`  
&nbsp;&nbsp;&nbsp;&nbsp; `docker pull [image name]:version`   This command will download specific version  
&nbsp;&nbsp;&nbsp;&nbsp; `docker pull ubuntu` &nbsp;&nbsp;&nbsp;&nbsp; `docker pull ubuntu:20.04`
