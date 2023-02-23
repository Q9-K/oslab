#include <blib.h>

size_t strlen(const char *s) {
	int length = 0;
	for(;s[length];) length++;
	return length;
}

char *strcpy(char *dst, const char *src) {
	for(int i=0;src[i];++i) dst[i]=src[i];
	return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
	char *res = dst;
	while (*src && n--) {
		*dst++ = *src++;
	}
	*dst = '\0';
	return res;
}

char *strcat(char *dst, const char *src) {
	int i=0;
	while(dst[i]) i++;
	for(int j=0;src[j];j++) dst[i]=src[j];
	return dst;
}

int strcmp(const char *s1, const char *s2) {
	int i=0;
	while(1){
		if(s1[i]>s2[i]) return 1;
		else if(s1[i]<s2[i]) return -1;
	}
	return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {
	while (n--) {
		if (*s1 != *s2) {
			return *s1 - *s2;
		}
		if (*s1 == 0) {
			break;
		}
		s1++;
		s2++;
	}
	return 0;
}

void *memset(void *s, int c, size_t n) {
	for(int i=0;i<n;++i){
		((int *)s)[i]=c;
	}
	return s;
}

void *memcpy(void *out, const void *in, size_t n) {
	char *csrc = (char *)in;
	char *cdest = (char *)out;
	for (int i = 0; i < n; i++) {
		cdest[i] = csrc[i];
	}
	return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
	char *t1=(char *)s1;
	char *t2=(char *)s2;
	for(int i=0;i<n;++i){
		if(t1[i]<t2[i]) return -1;
		else if(t1[i]>t2[i]) return 1;
	}
	return 0;
}
