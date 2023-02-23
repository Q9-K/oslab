#include <blib.h>

size_t strlen(const char *s) {
	char *str = s;
	size_t lens = 0;
	while(*str){
		lens++;
		str++;
	}
	return lens;
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
	for(int j=0;src[j];j++) dst[i++]=src[j];
	return dst;
}

int strcmp(const char *s1, const char *s2) {
	int i=0;
	while(s1[i]||s2[i]){
		if(s1[i]>s2[i]) return 1;
		else if(s1[i]<s2[i]) return -1;
		i++;
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
	char *str = (char *)s;
	for(int i=0;i<n;++i) str[i]=c;
	return (void *)str;
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
	char *str1 = (char *)s1;
	char *str2 = (char *)s2;
	for(int i=0;i<n;++i,str1++,str2++){
		if(*str1>*str2) return 1;
		else if(*str1<*str2) return -1;
	}
	return 0;
}
