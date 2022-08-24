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

**check image stats** : `docker system df`  

**delete images** : `docker rmi [-f] [img_id or img name]`


### Container

**run a image** : `docker run [options] image [command]`  
options:
&nbsp;&nbsp;&nbsp;&nbsp;`--name`: name for container
&nbsp;&nbsp;&nbsp;&nbsp;`-d`    : run container in background(detached mode)  
&nbsp;&nbsp;&nbsp;&nbsp;`-i`    : run docker in interative mode, normally used with '-t'  
&nbsp;&nbsp;&nbsp;&nbsp;`-t`    : allocate a pesudo TTY,normally used with `-i`  
&nbsp;&nbsp;&nbsp;&nbsp;`-P`    : random port  
&nbsp;&nbsp;&nbsp;&nbsp;`-p`    : specific port `-p 8080:80`  

**see all running image** : `docker ps [options]`  
